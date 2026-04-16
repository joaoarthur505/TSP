#pragma once

#include "Solution.h"

class Data;

class AbstractSolver
{
public:
	AbstractSolver();

	enum Type
	{
		Random,
		NearestNeighbor,
		GRASP,
		VariableNeighborhoodDecent,
	};

	virtual bool solve() = 0;

	Solution solution;

protected:
	const Data& data;
};
