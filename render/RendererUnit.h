//
// Created by chan on 2017/9/17.
//

#ifndef MARKDOWNPARSER_UNIT_H
#define MARKDOWNPARSER_UNIT_H

typedef enum
{
	TITLE_1, // #
	TITLE_2,
	TITLE_3,
	TITLE_4,
	TITLE_5,
	BOLD,
	ITALIC,
	ORDER_LIST, //*
	STRING, //a-z
	UNORDERED_LIST, // -
	REFERENCE, // >
	IMAGE,
	LINK,
	NEW_LINE, //\n \r
} RENDERER_UNIT;


#endif //MARKDOWNPARSER_UNIT_H
