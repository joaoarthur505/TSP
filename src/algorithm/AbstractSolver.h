#pragma once

#include "output/Solution.h"

class Data;
class Parameters;

class AbstractSolver
{
public:
	AbstractSolver();
	virtual ~AbstractSolver() = default;

	virtual bool solve() = 0;

	Solution solution;

protected:
	const Data& data;
	const Parameters& params;
};
