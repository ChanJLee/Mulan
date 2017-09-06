//
// Created by chan on 2017/8/20.
//

#ifndef MARKDOWNPARSER_LEXICAPARSER_H
#define MARKDOWNPARSER_LEXICAPARSER_H

#include "../symbol/Symbol.h"
#include "../token/Token.h"

class LexicalParser
{
private:
	const Text mInputStream;
	Cursor mCursor = 0;
	TokenStream mTokenStream;
public:
	LexicalParser(const Text &input);
	TokenStream build();
	virtual ~LexicalParser();
private:

	void fetchNextToken();
	void handleHash();
	void handleBlank();
	void handleStar();
	void handleNumber();
	void handleDashes();
	void handleEnd();
	void handleString();
	void handleDot();
	void handleReference();
};


#endif //MARKDOWNPARSER_LEXICAPARSER_H
