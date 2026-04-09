#include <iostream>

#include "Loader.h"
#include "RandomSolver.h"

int main()
{
	Loader loader;
	loader.load("data/ulysses16.tsp");

	RandomSolver solver;
	solver.solve();

	return 0;
}
