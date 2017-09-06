//
// Created by chan on 2017/9/5.
//

#ifndef MARKDOWNPARSER_GRAMMERPARSER_H
#define MARKDOWNPARSER_GRAMMERPARSER_H


#include "../token/Token.h"
class GrammarParser
{
	const TokenStream& mTokenStream;
public:
	GrammarParser(const TokenStream &mTokenStream);


};


#endif //MARKDOWNPARSER_GRAMMERPARSER_H
