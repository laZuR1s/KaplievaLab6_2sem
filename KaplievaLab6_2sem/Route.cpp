#include "Route.h"

ROUTE::ROUTE(std::ifstream& file)
{
	file.getline(startingPoint, m);
	file.getline(endingPoint, m);
	file >> length;
	file.ignore();
	if (!file.eof())
	{
		char delimLine[255];
		file.getline(delimLine, 255);
	}
}

void ROUTE::print()
{
	std::cout << startingPoint <<"- " << endingPoint << '\n' << length << '\n' << "====================\n";
}

int ROUTE::compare(const ROUTE& route)
{
	int result = -1;
	if (length<route.length)
		result = 1;
	else
		if (length==route.length)
			result = 0;
	return result;
}

int ROUTE::getLength()
{
	return length;
}

std::string ROUTE::getStartingPoint()
{
	return startingPoint;
}

std::string ROUTE::getEndingingPoint()
{
	return endingPoint;
}


