#pragma once

#include "AbstractSolver.h"
#include "input/Parameters.h"

class Solver : public AbstractSolver
{
public:
	bool solve(Parameters::SolverType type);
	bool solve() override;
};
