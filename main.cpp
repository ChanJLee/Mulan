#include <iostream>

#include <fstream>
#include "lexica/LexicalParser.h"
#include <sstream>

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

	return 0;
}