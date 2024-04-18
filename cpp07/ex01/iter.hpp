#pragma once

#include <iostream>

template<typename T>
void	iter(T *array, size_t len, void (*fun)(const T &))
{
	for (size_t i = 0; i < len; ++i)
		fun(array[i]);
}