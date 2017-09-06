cmake_minimum_required(VERSION 3.6)
project(MarkDownParser)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp symbol/Symbol.h lexica/LexicalParser.cpp lexica/LexicalParser.h mark/Mark.h nt/NormalType.h token/Token.h log/Logger.h utils/CharUtils.h grammer/GrammarParser.cpp grammer/GrammarParser.h)
add_executable(MarkDownParser ${SOURCE_FILES})