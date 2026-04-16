#include "Solver.h"

#include <stdexcept>

#include "RandomSolver.h"
#include "NearestNeighborSolver.h"
#include "GraspSolver.h"

using namespace std;

bool Solver::solve()
{
	Type type = GRASP;

	AbstractSolver* solver = nullptr;
	switch (type)
	{
	case AbstractSolver::Random: solver = new RandomSolver(); break;
	case AbstractSolver::NearestNeighbor: solver = new NearestNeighborSolver(); break;
	case AbstractSolver::GRASP: solver = new GraspSolver(); break;
	default: throw runtime_error("Unknown solver type");
	}

	bool ret = solver->solve();
	delete solver;

	return ret;
}
