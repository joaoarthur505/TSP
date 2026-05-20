#include "Solver.h"

#include <iostream>
#include <stdexcept>

#include "input/Parameters.h"

#include "GraspSolver.h"
#include "IteratedLocalSearchSolver.h"
#include "NearestNeighborSolver.h"
#include "RandomSolver.h"
#include "VNDSolver.h"

using namespace std;

bool Solver::solve(Parameters::SolverType type) {
	AbstractSolver* solver = nullptr;
	switch (type)
	{
		case Parameters::GRASP: solver = new GraspSolver(); break;
		case Parameters::IteratedLocalSearch: solver = new IteratedLocalSearchSolver(); break;
		case Parameters::NearestNeighbor: solver = new NearestNeighborSolver(); break;
		case Parameters::Random: solver = new RandomSolver(); break;
		case Parameters::VariableNeighborhoodDecent: solver = new VNDSolver(); break;
		default: throw runtime_error("Unknown solver type");
	}

	const bool ret = solver->solve();
	if (ret) solution = solver->solution;
	delete solver;

	return ret;
}

bool Solver::solve()
{
	return solve(params.solverType);
}
