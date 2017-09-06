//
// Created by chan on 2017/9/4.
//

#ifndef MARKDOWNPARSER_CHARUTILS_H
#define MARKDOWNPARSER_CHARUTILS_H

#include "../token/Token.h"

#ifdef IS_NUMBER
#undef IS_NUMBER
#endif

#ifdef IS_END
#undef IS_END
#endif

#ifdef IS_VALID_CHAR
#undef IS_VALID_CHAR
#endif

#define IS_END(ch) ((ch) == '\r' || (ch) == '\n')

#define IS_VALID_CHAR(ch) ((ch) != ']' && (ch) != ')' && \
		!IS_END(ch) \
	)

#define IS_NUMBER(ch) ((ch) >= '0' && (ch) <= '9')

#endif //MARKDOWNPARSER_CHARUTILS_H
