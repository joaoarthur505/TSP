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
	};

	virtual bool solve() = 0;

protected:
	const Data& data;

	Solution solution;
};
