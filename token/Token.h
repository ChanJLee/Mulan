//
// Created by chan on 2017/9/4.
//

#ifndef MARKDOWNPARSER_TOKEN_H
#define MARKDOWNPARSER_TOKEN_H

#include <string>
#include <stddef.h>
#include <vector>
#include "../symbol/Symbol.h"

typedef std::string::value_type Char;

typedef std::string Text;

typedef size_t Position;

class Token
{
public:
	SYMBOL_TYPE type;
	Text text;
public:
	Token(SYMBOL_TYPE type, const Text &str, Position pos, Text::size_type len)
		: type(type), text(str, pos, len)
	{
	}

	Token(SYMBOL_TYPE type)
		: type(type)
	{}
};

typedef std::vector<Token *> TokenStream;
typedef TokenStream::size_type Cursor;

#endif //MARKDOWNPARSER_TOKEN_H
