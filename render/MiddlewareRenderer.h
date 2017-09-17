//
// Created by chan on 2017/9/13.
//

#ifndef MARKDOWNPARSER_MIDDLEWARERENDERER_H
#define MARKDOWNPARSER_MIDDLEWARERENDERER_H

#include "../token/Token.h"
#include "RendererUnit.h"
virtual class MiddlewareRenderer {
public:
	virtual ~MiddlewareRenderer()
	{

	}

	virtual void render(RENDERER_UNIT unit, const Text&... texture) = 0;
	virtual void begin() = 0;
	virtual void end() = 0;
};

#endif //MARKDOWNPARSER_MIDDLEWARERENDERER_H
