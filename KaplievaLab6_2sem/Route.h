#pragma once

#include<iostream>
#include<fstream>
#include<cstring>
#include<string>

const int m = 35; //max length of str

struct ROUTE
{
private:
	char startingPoint[m];
	char endingPoint[m];
	int length;
public:
	ROUTE(){}
	ROUTE(std::ifstream& file);
	void print();
	int compare(const ROUTE& route);
	int getLength();
	std::string getStartingPoint();
	std::string getEndingingPoint();
};
	