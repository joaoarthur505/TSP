#pragma once

#include "Solver.h"

class Neighborhood;

class VNDSolver : public Solver
{
public:
	VNDSolver();
	~VNDSolver() override;
	
	bool solve() override;
	bool solve(const Solution& initial);

private:
	std::vector<Neighborhood*> neighborhoods;
};
