//
// Created by chan on 2017/9/13.
//

#ifndef MARKDOWNPARSER_MIDDLEWARERENDERER_H
#define MARKDOWNPARSER_MIDDLEWARERENDERER_H

#include "../token/Token.h"
#include "RendererUnit.h"

class MiddlewareRenderer
{
public:
	virtual ~MiddlewareRenderer()
	{

	}

	virtual void begin() = 0;
	virtual void end() = 0;
	virtual void renderTitle(RENDERER_UNIT unit, const Text &content) = 0;
	virtual void renderTexture(const Text &content) = 0;
	virtual void renderTypeface(RENDERER_UNIT unit, const Text &content) = 0;
	virtual void renderOrderList(const Text &num, const Text &content) = 0;
	virtual void renderNewLine() = 0;
	virtual void renderImage(const Text &label, const Text &url) = 0;
	virtual void renderLink(const Text &label, const Text &url) = 0;
	virtual void renderReference(const Text &content) = 0;
};

#endif //MARKDOWNPARSER_MIDDLEWARERENDERER_H
