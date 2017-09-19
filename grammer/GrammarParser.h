//
// Created by chan on 2017/9/5.
//

#ifndef MARKDOWNPARSER_GRAMMERPARSER_H
#define MARKDOWNPARSER_GRAMMERPARSER_H


#include "../token/Token.h"
#include "../render/MiddlewareRenderer.h"
#include <vector>

typedef std::vector<MiddlewareRenderer *> MiddlewareRendererContainer;

class GrammarParser
{
	const TokenStream &mTokenStream;
	MiddlewareRendererContainer mRenderers;
public:
	GrammarParser(const TokenStream &mTokenStream);

	void registerRenderer(MiddlewareRenderer *renderer);
	void unregisterRenderer(MiddlewareRenderer *renderer);

	void parse();
private:
	void handleHash(TokenStream::const_iterator &it);
	void handleStar(TokenStream::const_iterator &it);
	void handleString(TokenStream::const_iterator &it);
	void handleNumber(TokenStream::const_iterator &it);
	bool isLineFirst(TokenStream::const_iterator &it);
	void handleNewLine();
	bool checkToken(TokenStream::const_iterator &it, int offset, SYMBOL_TYPE type);
	void handleReference(TokenStream::const_iterator &it);
	void handleDashes(TokenStream::const_iterator &iter);
	void handleExclamationMark(TokenStream::const_iterator &iter);
	void handleLeftSquareBrackets(TokenStream::const_iterator &iter);
};


#endif //MARKDOWNPARSER_GRAMMERPARSER_H
