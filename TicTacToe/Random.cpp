#include "Random.h"

Random::Random()
	: gen(std::random_device{}()) {}

int Random::generateNum(int min, int max)
{
	std::uniform_int_distribution<int> dist(min, max);

	return dist(gen);
}
