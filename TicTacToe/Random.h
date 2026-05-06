#pragma once
#include <random>

class Random
{
private:
	std::mt19937 gen;

public:
	Random();
		
	int generateNum(int min = 0, int max = INT_MAX - 1);
};

