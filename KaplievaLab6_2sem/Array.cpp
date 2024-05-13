#include "Array.h"

ARRAY::ARRAY(std::ifstream& file)
{
	file >> size;
	file.ignore();
	arr = new ptrROUTE[size];
	for (size_t i{}; i < size; ++i)
	{
		arr[i] = new ROUTE(file);
	}
	file.close();
}

void ARRAY::print()
{
	for (size_t i{}; i < size; ++i)
	{
		arr[i]->print();
	}
}

void ARRAY::sorting()
{
	for (size_t count{ size }; count >= 2; --count)
	{
		for (size_t i{ 0 }; i < count - 1; ++i)
		{
			if (arr[i]->compare(*arr[i + 1]) > 0)
				std::swap(arr[i], arr[i + 1]);
		}
	}
}

bool ARRAY::to_binary(const char* file_name)
{

	bool result{ true };
	std::ofstream file_bin(file_name, std::ios::binary);
	if (!file_bin.is_open())
		result = false;
	else
	{
		for (size_t i{}; i < size; ++i)
		{
			file_bin.write((char*)arr[i], sizeof(ROUTE));
		}
		file_bin.close();
	}
	return result;

}
