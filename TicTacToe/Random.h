#pragma once
#include <random>

class Random
{
protected:

	std::mt19937 gen;


public:

	Random();
		
	// min always 0
	int generateNum(int max);
	

};

