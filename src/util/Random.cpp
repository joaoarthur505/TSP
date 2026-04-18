#include "Random.h"

using namespace std;

unsigned int Random::_seed;

std::mt19937 Random::engine;
std::uniform_int_distribution<> Random::uniformIntDistribution;
std::uniform_real_distribution<> Random::uniformRealDistribution;

void Random::seed(const unsigned int seed)
{
	_seed = seed;
	srand(_seed);
	engine.seed(_seed);
}

unsigned int Random::seed()
{
	return _seed;
}

int Random::randomInt()
{
	return uniformIntDistribution(engine);
}

int Random::randomInt(const int a, const int b)
{
	return uniformIntDistribution(engine, uniform_int_distribution<>::param_type(a, b));
}

double Random::randomDouble()
{
	return uniformRealDistribution(engine);
}

double Random::randomDouble(const double a, const double b)
{
	return uniformRealDistribution(engine, uniform_real_distribution<>::param_type(a, b));
}