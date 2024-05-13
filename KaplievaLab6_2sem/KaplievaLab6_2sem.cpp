#include <Windows.h>
#include "Array.h"

std::string exp_route(std::ifstream& file_bin, int& count);

int main()
{
   
	std::ifstream file_txt("routes.txt");
	if (file_txt)
	{
		ARRAY arr(file_txt);
		arr.print();
		std::cout << "\n=======SORTED=======\n";
		arr.sorting();
		arr.print();
		//arr.to_binary("routes_bin.txt");
		std::ifstream file_bin("routes_bin.txt", std::ios::binary);
		if (file_bin)
		{
			int count{};
			std::string res = exp_route(file_bin, count);
			if (count > 1)
				std::cout << "There are " << count << " the longest routes: " << res << '\n';
			else
				std::cout << "The longest route is: " << res << '\n';
		}
		else std::cout << "bin file error\n";
	}
	else std::cout << "text file error\n";
}

std::string exp_route(std::ifstream& file_bin, int& count)
{
	std::string result = "";
	ROUTE route;
	count = 1;
	int max{};
	while (file_bin.read((char*)(&route), sizeof(ROUTE)))
	{
		if (route.getLength() > max)
		{
			count = 1;
			max = route.getLength();
			result = route.getStartingPoint()+route.getEndingingPoint();
		}
		else
			if (route.getLength() == max)
			{
				if (result.find(route.getStartingPoint() + route.getEndingingPoint()) == std::string::npos)
				{
					count++;
					result += ", " + route.getStartingPoint() + route.getEndingingPoint();
				}
			}
	}
	return result;
}