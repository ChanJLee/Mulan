//
// Created by chan on 2017/9/5.
//

#include "GrammarParser.h"
#include <algorithm>

GrammarParser::GrammarParser(const TokenStream &mTokenStream)
	: mTokenStream(mTokenStream)
{}

void GrammarParser::registerRenderer(MiddlewareRenderer *renderer)
{
	mRenderers.push_back(renderer);
}

void GrammarParser::unregisterRenderer(MiddlewareRenderer *renderer)
{
	for (MiddlewareRendererContainer::iterator iterator = mRenderers.begin(); iterator != mRenderers.end();
		 ++iterator) {
		if (*iterator == renderer) {
			mRenderers.erase(iterator);
			return;
		}
	}
}
void GrammarParser::parse()
{

	std::for_each(mRenderers.cbegin(), mRenderers.cend(), [](MiddlewareRenderer *renderer)
	{
		renderer->begin();
	});

	for (TokenStream::const_iterator iterator = mTokenStream.cbegin(); iterator != mTokenStream.cend(); ++iterator) {
		Token *token = *iterator;
		if (token->type == SYMBOL_TYPE::HASH) {
			handleHash(iterator);
		}
		else if (token->type == SYMBOL_TYPE::STAR) {
			handleStar(iterator);
		}
		else if (token->type == SYMBOL_TYPE::NUMBER) {
			handleNumber(iterator);
		}
		else if (token->type == SYMBOL_TYPE::NEW_LINE) {
			handleNewLine();
		}
		else {
			handleString(iterator);
		}
	}

	std::for_each(mRenderers.cbegin(), mRenderers.cend(), [](MiddlewareRenderer *renderer)
	{
		renderer->end();
	});
}

void GrammarParser::handleHash(TokenStream::const_iterator &it)
{

	TokenStream::const_iterator nextIt = it + 1;
	if (nextIt == mTokenStream.cend()) {
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->render(RENDERER_UNIT::STRING, (*it)->text);
		});
		return;
	}

	bool prevTokenIsEnd = isLineFirst(it);
	bool nextTokenIsBlank = (*nextIt)->type == SYMBOL_TYPE::BLANK;
	++nextIt;
	bool nextNextTokenIsString = nextIt != mTokenStream.cend() && (*nextIt)->type == SYMBOL_TYPE::STRING;

	//当是新的一行 并且中间至 #号后面跟了一个空格符 且后面还有字符 那么就认为是一个标题
	if (prevTokenIsEnd && nextTokenIsBlank && nextNextTokenIsString) {

		RENDERER_UNIT unit = RENDERER_UNIT::TITLE_5;
		switch ((*it)->text.size()) {
			case 1: unit = RENDERER_UNIT::TITLE_1;
				break;
			case 2: unit = RENDERER_UNIT::TITLE_2;
				break;
			case 3: unit = RENDERER_UNIT::TITLE_3;
				break;
			case 4: unit = RENDERER_UNIT::TITLE_4;
				break;
			default: break;
		}

		//将读取指针后移
		it = nextIt;
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->render(unit, (*nextIt)->text);
		});
		return;
	}

	std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
	{
		renderer->render(RENDERER_UNIT::STRING, (*it)->text);
	});
}

void GrammarParser::handleStar(TokenStream::const_iterator &it)
{
	TokenStream::const_iterator nextToken = it + 1;
	if (nextToken == mTokenStream.cend()) {
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->render(RENDERER_UNIT::STRING, (*it)->text);
		});
		return;
	}

	//如果下一个单词也是star 那么就当错误处理，吃掉状态
	if ((*nextToken)->type == SYMBOL_TYPE::STAR) {
		it = nextToken;
		return;
	}

	bool nextTokenIsString = (*nextToken)->type == SYMBOL_TYPE::STRING;
	TokenStream::const_iterator nextNextToken = nextNextToken + 1;
	bool nextNextTokenIsStar = nextNextToken != mTokenStream.cend() &&
		(*nextNextToken)->type == SYMBOL_TYPE::STAR &&
		(*nextNextToken)->text.size() == (*it)->text.size();

	if (nextNextTokenIsStar && nextTokenIsString) {

		RENDERER_UNIT unit = RENDERER_UNIT::BOLD;
		if ((*it)->text.size() == 1) {
			unit = RENDERER_UNIT::ITALIC;
		}

		it = nextNextToken;
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->render(unit, (*nextToken)->text);
		});
		return;
	}

	std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
	{
		renderer->render(RENDERER_UNIT::STRING, (*it)->text);
	});
}

void GrammarParser::handleString(TokenStream::const_iterator &it)
{
	std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
	{
		renderer->render(RENDERER_UNIT::STRING, (*it)->text);
	});
}

void GrammarParser::handleNumber(TokenStream::const_iterator &it)
{
	bool isLineFirst = isLineFirst(it);
	TokenStream::const_iterator nextToken = it + 1;
	if (!isLineFirst || nextToken == mTokenStream.cend() || (*nextToken)->type != SYMBOL_TYPE::DOT) {
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->render(RENDERER_UNIT::STRING, (*it)->text);
		});
		return;
	}

	//check next token is blank
	++nextToken;
	if (nextToken == mTokenStream.cend() || (*nextToken)->type != SYMBOL_TYPE::BLANK) {
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->render(RENDERER_UNIT::STRING, (*it)->text);
		});
		return;
	}

	//check next token is string
	++nextToken;
	if (nextToken == mTokenStream.cend() || (*nextToken)->type != SYMBOL_TYPE::STRING) {
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->render(RENDERER_UNIT::STRING, (*it)->text);
		});
		return;
	}

	//render order list
	std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
	{
		renderer->render(RENDERER_UNIT::ORDER_LIST, (*it)->text, (*nextToken)->text);
	});
	it = nextToken;
}

inline bool GrammarParser::isLineFirst(TokenStream::const_iterator &it)
{
	if (it == mTokenStream.cbegin()) {
		return true;
	}

	return (*(it - 1))->type == SYMBOL_TYPE::NEW_LINE;
}

void GrammarParser::handleNewLine()
{
	std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
	{
		renderer->render(RENDERER_UNIT::NEW_LINE);
	});
}
