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
		else if (token->type == SYMBOL_TYPE::REFERENCE) {
			handleReference(iterator);
		}
		else if (token->type == SYMBOL_TYPE::DASHES) {
			handleDashes(iterator);
		}
		else if (token->type == SYMBOL_TYPE::EXCLAMATION_MARK) {
			handleExclamationMark(iterator);
		}
		else if (token->type == SYMBOL_TYPE::LEFT_SQUARE_BRACKETS) {
			handleLeftSquareBrackets(iterator);
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
		handleString(it);
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

	handleString(it);
}

void GrammarParser::handleString(TokenStream::const_iterator &it)
{
	std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
	{
		renderer->renderTexture((*it)->text);
	});

	if (checkToken(it, 1, SYMBOL_TYPE::NEW_LINE)) {
		++it;
	}
}

void GrammarParser::handleNumber(TokenStream::const_iterator &it)
{
	if (isLineFirst(it) &&
		checkToken(it, 1, SYMBOL_TYPE::DOT) &&
		checkToken(it, 2, SYMBOL_TYPE::BLANK) &&
		checkToken(it, 3, SYMBOL_TYPE::STRING)) {

		TokenStream::const_iterator nextToken = it + 3;
		//render order list
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->renderOrderList((*it)->text, (*nextToken)->text);
		});
		it = nextToken;
		return;
	}

	handleString(it);
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

void GrammarParser::handleReference(TokenStream::const_iterator &it)
{
	if (isLineFirst(it) && checkToken(it, 1, SYMBOL_TYPE::BLANK) && checkToken(it, 2, SYMBOL_TYPE::STRING)) {
		it += 2;
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->renderReference((*it)->text);
		});
		return;
	}

	handleString(it);
}

void GrammarParser::handleDashes(TokenStream::const_iterator &it)
{
	if (isLineFirst(it) && checkToken(it, 1, SYMBOL_TYPE::BLANK) && checkToken(it, 2, SYMBOL_TYPE::STRING)) {
		it += 2;
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->renderUnorderedList((*it)->text);
		});
		return;
	}

	handleString(it);
}

void GrammarParser::handleExclamationMark(TokenStream::const_iterator &it)
{
	if (isLineFirst(it) &&
		checkToken(it, 1, SYMBOL_TYPE::LEFT_SQUARE_BRACKETS) &&
		checkToken(it, 2, SYMBOL_TYPE::STRING) &&
		checkToken(it, 3, SYMBOL_TYPE::RIGHT_SQUARE_BRACKETS) &&
		checkToken(it, 4, SYMBOL_TYPE::LEFT_PARENTHESES) &&
		checkToken(it, 5, SYMBOL_TYPE::STRING) &&
		checkToken(it, 6, SYMBOL_TYPE::RIGHT_PARENTHESES)) {
		TokenStream::const_iterator label = it + 2;
		TokenStream::const_iterator url = it + 5;
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->renderImage((*label)->text, (*url)->text);
		});
		it = url;
		return;
	}

	handleString(it);
}

void GrammarParser::handleLeftSquareBrackets(TokenStream::const_iterator &it)
{
	if (isLineFirst(it) &&
		checkToken(it, 1, SYMBOL_TYPE::STRING) &&
		checkToken(it, 2, SYMBOL_TYPE::RIGHT_SQUARE_BRACKETS) &&
		checkToken(it, 3, SYMBOL_TYPE::LEFT_PARENTHESES) &&
		checkToken(it, 4, SYMBOL_TYPE::STRING) &&
		checkToken(it, 5, SYMBOL_TYPE::RIGHT_PARENTHESES)) {
		TokenStream::const_iterator label = it + 1;
		TokenStream::const_iterator url = it + 4;
		std::for_each(mRenderers.begin(), mRenderers.end(), [&](MiddlewareRenderer *renderer)
		{
			renderer->renderLink((*label)->text, (*url)->text);
		});
		it = url;
		return;
	}

	handleString(it);
}
