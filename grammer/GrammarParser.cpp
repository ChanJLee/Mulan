//
// Created by chan on 2017/9/5.
//

#include "GrammarParser.h"

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
			renderer->renderTexture((*it)->text);
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
			renderer->renderTitle(unit, (*nextIt)->text);
		});
		return;
	}

	std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
	{
		renderer->renderTexture((*it)->text);
	});
}

void GrammarParser::handleStar(TokenStream::const_iterator &it)
{
	if (!checkToken(it, 1, SYMBOL_TYPE::STRING) && !checkToken(it, 1, SYMBOL_TYPE::STAR)) {
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->renderTexture((*it)->text);
		});
		return;
	}


	//如果下一个单词也是star 那么就当错误处理，吃掉状态
	if (checkToken(it, 1, SYMBOL_TYPE::STAR)) {
		++it;
		return;
	}

	if (checkToken(it, 1, SYMBOL_TYPE::STRING) && checkToken(it, 2, SYMBOL_TYPE::STAR)) {

		RENDERER_UNIT unit = RENDERER_UNIT::BOLD;
		if ((*it)->text.size() == 1) {
			unit = RENDERER_UNIT::ITALIC;
		}

		TokenStream::const_iterator nextToken = it + 1;
		it += 2;

		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->renderTypeface(unit, (*nextToken)->text);
		});
		return;
	}

	std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
	{
		renderer->renderTexture((*it)->text);
	});
}

void GrammarParser::handleString(TokenStream::const_iterator &it)
{
	std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
	{
		renderer->renderTexture((*it)->text);
	});
}

void GrammarParser::handleNumber(TokenStream::const_iterator &it)
{
	bool isAtNewLine = isLineFirst(it);
	if (!isAtNewLine || !checkToken(it, 1, SYMBOL_TYPE::DOT) || !checkToken(it, 2, SYMBOL_TYPE::STRING)) {
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->renderTexture((*it)->text);
		});
		return;
	}

	TokenStream::const_iterator nextToken = it + 2;
	//render order list
	std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
	{
		renderer->renderOrderList((*it)->text, (*nextToken)->text);
	});
	it = nextToken;
}

inline bool GrammarParser::isLineFirst(TokenStream::const_iterator &it)
{
	if (it == mTokenStream.cbegin()) {
		return true;
	}

	return checkToken(it, -1, SYMBOL_TYPE::NEW_LINE);
}

void GrammarParser::handleNewLine()
{
	std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
	{
		renderer->renderNewLine();
	});
}

bool GrammarParser::checkToken(TokenStream::const_iterator &it, int offset, SYMBOL_TYPE type)
{
	TokenStream::const_iterator target = it + offset;
	if (target < mTokenStream.cbegin() || target >= mTokenStream.cend()) {
		return false;
	}

	return (*target)->type == type;
}
