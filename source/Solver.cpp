#include "Solver.h"

#include "RandomSolver.h"
#include "NearestNeighborSolver.h"

bool Solver::solve()
{
	Type type = NearestNeighbor;

	AbstractSolver* solver = nullptr;
	switch (type)
	{
	case AbstractSolver::Random: solver = new RandomSolver(); break;
	case AbstractSolver::NearestNeighbor: solver = new NearestNeighborSolver(); break;
	default: break;
	}

	bool ret = solver->solve();
	delete solver;

	return ret;
}
