#include <iostream>

#include <fstream>
#include "lexica/LexicalParser.h"
#include "grammer/GrammarParser.h"
#include "render/HtmlRenderer.h"

int main()
{
	std::cout << "start" << std::endl;
	std::ifstream ifstream;
	ifstream.open("/Users/chan/Downloads/shanbay-beaver-doc/etc.md");
	std::stringstream buffer;
	buffer << ifstream.rdbuf();
	std::string contents(buffer.str());
	std::cout << contents << std::endl;
	LexicalParser lexicalParser(contents);
	auto vec = lexicalParser.build();

	int index = 0;
	std::for_each(vec.begin(), vec.end(), [&](Token *token)
	{
		std::cout << index << "\t" << token->type << "\t" << token->text << std::endl;
		++index;
	});

	GrammarParser grammarParser(vec);
	grammarParser.registerRenderer(new HtmlRenderer());
	grammarParser.parse();

	return 0;
}