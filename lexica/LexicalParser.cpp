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
	while (!eof()) {
		fetchNextToken();
	}

	return mTokenStream;
}

void LexicalParser::fetchNextToken()
{
	if (eof()) {
		if (mTokenStream.empty() || mTokenStream.back()->type != NEW_LINE)
			mTokenStream.push_back(new Token(NEW_LINE));
		return;
	}

	Char ch = getChar();

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
		handleExclamationMark();
		return;
	}

	if (ch == '[') {
		handleLeftSquareBrackets();
		return;
	}

	if (ch == ']') {
		handleRightSquareBrackets();
		return;
	}

	if (ch == '(') {
		handleLeftParentheses();
		return;
	}

	if (ch == ')') {
		handleRightParentheses();
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
	Text::size_type count = 0;
	while (mCursor < mInputStream.size() && mInputStream.at(mCursor) == ' ') {
		++count;
		++mCursor;
	}

	mTokenStream.push_back(new Token(BLANK, mInputStream, mCursor - count, count));
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
	mTokenStream.push_back(new Token(NEW_LINE, mInputStream, mCursor - 1, 1));
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

inline bool LexicalParser::eof()
{
	return mCursor >= mInputStream.size();
}

inline Char LexicalParser::getChar()
{
	return mInputStream.at(mCursor);
}

inline void LexicalParser::next()
{
	++mCursor;
}

void LexicalParser::handleExclamationMark()
{
	next();
	mTokenStream.push_back(new Token(EXCLAMATION_MARK));
}

void LexicalParser::handleLeftSquareBrackets()
{
	next();
	mTokenStream.push_back(new Token(LEFT_SQUARE_BRACKETS));
}

void LexicalParser::handleRightSquareBrackets()
{
	next();
	mTokenStream.push_back(new Token(RIGHT_SQUARE_BRACKETS));
}

void LexicalParser::handleLeftParentheses()
{
	next();
	mTokenStream.push_back(new Token(LEFT_PARENTHESES));
}

void LexicalParser::handleRightParentheses()
{
	next();
	mTokenStream.push_back(new Token(RIGHT_PARENTHESES));
}
