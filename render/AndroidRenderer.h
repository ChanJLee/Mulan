//
// Created by chan on 2017/9/19.
//

#ifndef MARKDOWNPARSER_ANDROIDRENDERER_H
#define MARKDOWNPARSER_ANDROIDRENDERER_H


#include "MiddlewareRenderer.h"
class AndroidRenderer : public MiddlewareRenderer
{
public:
	void begin() override;
	void end() override;
	void renderTitle(RENDERER_UNIT unit, const Text &content) override;
	void renderTexture(const Text &content) override;
	void renderTypeface(RENDERER_UNIT unit, const Text &content) override;
	void renderOrderList(const Text &num, const Text &content) override;
	void renderUnorderedList(const Text &content) override;
	void renderNewLine() override;
	void renderImage(const Text &label, const Text &url) override;
	void renderLink(const Text &label, const Text &url) override;
	void renderReference(const Text &content) override;

};


#endif //MARKDOWNPARSER_ANDROIDRENDERER_H
