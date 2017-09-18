//
// Created by chan on 2017/8/20.
//

#ifndef MARKDOWNPARSER_SYMBOL_H
#define MARKDOWNPARSER_SYMBOL_H

#pragma once

enum class SYMBOL_TYPE
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
	NEW_LINE, //\n \r
};


#endif //MARKDOWNPARSER_SYMBOL_H
