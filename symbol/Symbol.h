//
// Created by chan on 2017/8/20.
//

#ifndef MARKDOWNPARSER_SYMBOL_H
#define MARKDOWNPARSER_SYMBOL_H

#include <stddef.h>

typedef enum
{
	BLANK,
	HASH, // #
	STAR, //*
	NUMBER,    // 0-9
	STRING, //a-z
	DOT, // .
	DASHES, // -
	REFERENCE, // >
	EXCLAMATION_MARK, //!
	LEFT_SQUARE_BRACKETS, //[
	RIGHT_SQUARE_BRACKETS, // ]
	LEFT_PARENTHESES, // (
	RIGHT_PARENTHESES, // )
	END, //\n \r
} SYMBOL_TYPE;


#endif //MARKDOWNPARSER_SYMBOL_H
