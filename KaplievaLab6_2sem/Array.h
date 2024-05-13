#pragma once
#include "Route.h"

using ptrROUTE = ROUTE*;

struct ARRAY {
	ptrROUTE* arr;
	size_t size;
	ARRAY(){}
	ARRAY(std::ifstream& file);
	void print();
	void sorting();
	bool to_binary(const char* file_name);
	~ARRAY()
	{
		for (size_t i{ 0 }; i < size; ++i)
			delete arr[i];
		delete[] arr;
	}
};