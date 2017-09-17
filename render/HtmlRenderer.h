//
// Created by chan on 2017/9/13.
//

#ifndef MARKDOWNPARSER_HTMLRENDERER_H
#define MARKDOWNPARSER_HTMLRENDERER_H


#include "MiddlewareRenderer.h"
class HtmlRenderer : public MiddlewareRenderer
{
public:
	void render(SYMBOL_TYPE type, const Text &... texture) override;
};


#endif //MARKDOWNPARSER_HTMLRENDERER_H
