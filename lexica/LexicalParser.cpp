//
// Created by chan on 2017/8/20.
//

#include "LexicalParser.h"
#include "../utils/CharUtils.h"
#include "../log/Logger.h"

LexicalParser::LexicalParser(const Text &input)
	: mInputStream(input)
{}

TokenStream LexicalParser::build()
{
	while (mCursor < mInputStream.size()) {
		fetchNextToken();
	}

	return mTokenStream;
}

void LexicalParser::fetchNextToken()
{
	if (mCursor >= mInputStream.size()) {
		if (mTokenStream.empty() || mTokenStream.back()->type != END)
			mTokenStream.push_back(new Token(END));
		return;
	}

	Char ch = mInputStream.at(mCursor);

	if (ch == ' ') {
		handleBlank();
		return;
	}

	if (ch == '#') {
		handleHash();
		return;
	}

	if (ch == '*') {
		handleStar();
		return;
	}

	if (IS_NUMBER(ch)) {
		handleNumber();
		return;
	}

	if (ch == '.') {
		handleDot();
		return;
	}

	if (ch == '-') {
		handleDashes();
		return;
	}

	if (ch == '>') {
		handleReference();
		return;
	}

	if (ch == '!') {
		++mCursor;
		mTokenStream.push_back(new Token(EXCLAMATION_MARK));
		return;
	}

	if (ch == '[') {
		++mCursor;
		mTokenStream.push_back(new Token(LEFT_SQUARE_BRACKETS));
		return;
	}

	if (ch == ']') {
		++mCursor;
		mTokenStream.push_back(new Token(RIGHT_SQUARE_BRACKETS));
		return;
	}

	if (ch == '(') {
		++mCursor;
		mTokenStream.push_back(new Token(LEFT_PARENTHESES));
		return;
	}

	if (ch == ')') {
		++mCursor;
		mTokenStream.push_back(new Token(RIGHT_PARENTHESES));
		return;
	}

	if (IS_END(ch)) {
		handleEnd();
		return;
	}

	handleString();
}

void LexicalParser::handleHash()
{
	Text::size_type count = 0;
	while (mCursor < mInputStream.size() && mInputStream.at(mCursor) == '#') {
		++count;
		++mCursor;
	}

	mTokenStream.push_back(new Token(HASH, mInputStream, mCursor - count, count));
}

void LexicalParser::handleBlank()
{
	Token *token = new Token(BLANK);

	while (mCursor < mInputStream.size() && mInputStream.at(mCursor) == ' ') {
		++mCursor;
	}

	mTokenStream.push_back(token);
}

void LexicalParser::handleStar()
{
	Text::size_type count = 0;
	while (mCursor < mInputStream.size() && mInputStream.at(mCursor) == '*') {
		++count;
		++mCursor;
	}

	mTokenStream.push_back(new Token(STAR, mInputStream, mCursor - count, count));
}

void LexicalParser::handleNumber()
{
	Text::size_type count = 0;
	while (mCursor < mInputStream.size() && IS_NUMBER(mInputStream.at(mCursor))) {
		++count;
		++mCursor;
	}

	mTokenStream.push_back(new Token(NUMBER, mInputStream, mCursor - count, count));
}

void LexicalParser::handleDashes()
{
	Text::size_type count = 0;
	while (mCursor < mInputStream.size() && mInputStream.at(mCursor) == '-') {
		++count;
		++mCursor;
	}

	mTokenStream.push_back(new Token(DASHES, mInputStream, mCursor - count, count));
}

inline void LexicalParser::handleEnd()
{
	//TODO windows
	++mCursor;
	mTokenStream.push_back(new Token(END, mInputStream, mCursor - 1, 1));
}

void LexicalParser::handleString()
{
	Text::size_type count = 0;
	while (mCursor < mInputStream.size() && IS_VALID_CHAR(mInputStream.at(mCursor))) {
		++count;
		++mCursor;
	}

	mTokenStream.push_back(new Token(STRING, mInputStream, mCursor - count, count));
}

LexicalParser::~LexicalParser()
{
	std::for_each(mTokenStream.begin(), mTokenStream.end(), [](Token *token)
	{
		delete token;
	});
}

inline void LexicalParser::handleDot()
{
	++mCursor;
	mTokenStream.push_back(new Token(DOT));
}

inline void LexicalParser::handleReference()
{
	++mCursor;
	mTokenStream.push_back(new Token(REFERENCE));
}
