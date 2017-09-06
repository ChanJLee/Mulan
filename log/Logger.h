//
// Created by chan on 2017/9/4.
//

#include <iostream>

template <typename T>
inline void log(const char *tag, T message)
{
	std::cout << tag << message << std::endl;
}