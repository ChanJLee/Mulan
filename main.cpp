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

#ifdef DEBUG
	int index = 0;
	std::for_each(vec.begin(), vec.end(), [&](Token *token)
	{
		std::cout << index << "\t" << "type: " << "\t";
		switch (token->type) {
			case SYMBOL_TYPE::BLANK: std::cout << "blank";
				break;
			case SYMBOL_TYPE::HASH: std::cout << "hash";
				break;
			case SYMBOL_TYPE::NUMBER: std::cout << "number";
				break;
			case SYMBOL_TYPE::STRING: std::cout << "string";
				break;
			case SYMBOL_TYPE::STAR: std::cout << "star";
				break;
			case SYMBOL_TYPE::DOT: std::cout << "dot";
				break;
			case SYMBOL_TYPE::DASHES: std::cout << "dashed";
				break;
			case SYMBOL_TYPE::REFERENCE: std::cout << "reference";
				break;
			case SYMBOL_TYPE::EXCLAMATION_MARK: std::cout << "!";
				break;
			case SYMBOL_TYPE::LEFT_SQUARE_BRACKETS: std::cout << "[";
				break;
			case SYMBOL_TYPE::RIGHT_SQUARE_BRACKETS: std::cout << "]";
				break;
			case SYMBOL_TYPE::LEFT_PARENTHESES: std::cout << "(";
				break;
			case SYMBOL_TYPE::RIGHT_PARENTHESES: std::cout << ")";
				break;
			case SYMBOL_TYPE::NEW_LINE: std::cout << "new line";
				break;
		}

		std::cout << "\t" << token->text << std::endl;
		++index;
	});
#endif

	GrammarParser grammarParser(vec);
	grammarParser.registerRenderer(new HtmlRenderer());
	grammarParser.parse();

	return 0;
}