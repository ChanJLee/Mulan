//
// Created by chan on 2017/9/13.
//

#include <iostream>
#include "HtmlRenderer.h"

void HtmlRenderer::begin()
{
	mStringBuilder << "<!DOCTYPE html><html><body>";
}

void HtmlRenderer::end()
{
	mStringBuilder << "</body></html>";
	std::cout << mStringBuilder.str();
}

void HtmlRenderer::renderTitle(RENDERER_UNIT unit, const Text &content)
{
	switch (unit) {
		case RENDERER_UNIT::TITLE_1: mStringBuilder << "<h1>" << content << "</h1>";
			break;
		case RENDERER_UNIT::TITLE_2: mStringBuilder << "<h2>" << content << "</h2>";
			break;
		case RENDERER_UNIT::TITLE_3: mStringBuilder << "<h3>" << content << "</h3>";
			break;
		case RENDERER_UNIT::TITLE_4: mStringBuilder << "<h4>" << content << "</h4>";
			break;
		default: mStringBuilder << "<h5>" << content << "</h5>";
			break;
	}
}
void HtmlRenderer::renderTexture(const Text &content)
{
	mStringBuilder << "<p>" << content << "</p>";
}
void HtmlRenderer::renderTypeface(RENDERER_UNIT unit, const Text &content)
{
	if (RENDERER_UNIT::BOLD == unit) {
		mStringBuilder << "<b>" << content << "</b>";
		return;
	}

	mStringBuilder << "<i>" << content << "</i>";
}
void HtmlRenderer::renderOrderList(const Text &num, const Text &content)
{
	mStringBuilder << "<b>" << num << ". " << content;
}

void HtmlRenderer::renderNewLine()
{
	mStringBuilder << "<br>";
}

void HtmlRenderer::renderImage(const Text &label, const Text &url)
{
	renderTitle(RENDERER_UNIT::TITLE_5, label);
	renderNewLine();
	mStringBuilder << "<image src=\"" << url << "\">";
}

void HtmlRenderer::renderLink(const Text &label, const Text &url)
{
	mStringBuilder << "<a href=\"" << url << "\">" << label << "</a>";
}

void HtmlRenderer::renderReference(const Text &content)
{
	mStringBuilder << "<span style=\"background-color:#ABB5BB;color:#ffffff;\">" << content << "</span>";
}
