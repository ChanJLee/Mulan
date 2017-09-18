//
// Created by chan on 2017/9/13.
//

#ifndef MARKDOWNPARSER_HTMLRENDERER_H
#define MARKDOWNPARSER_HTMLRENDERER_H


#include "MiddlewareRenderer.h"
#include <sstream>

typedef std::stringstream StringBuilder;

class HtmlRenderer: public MiddlewareRenderer
{
private:
	StringBuilder mStringBuilder;
public:
	void begin() override;
	void end() override;
	void renderTitle(RENDERER_UNIT unit, const Text & content) override;
	void renderTexture(const Text &content) override;
	void renderTypeface(RENDERER_UNIT unit, const Text &content) override;
	void renderOrderList(const Text &num, const Text &content) override;
	void renderNewLine() override;
	void renderImage(const Text &label, const Text &url) override;
	void renderLink(const Text &label, const Text &url) override;
	void renderReference(const Text &content) override;
};

#endif //MARKDOWNPARSER_HTMLRENDERER_H
