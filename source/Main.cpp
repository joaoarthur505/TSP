#include <iostream>
#include <format>

#include "Loader.h"

#include "Solver.h"

#include "Timer.h"

using namespace std;

int main()
{
	Loader loader;
	loader.load("data/ulysses16.tsp");

	Timer timer;

	Solver solver;
	solver.solve();

	cout << format("Time: {:.6f}s", timer.stop()) << endl;

	return 0;
}
