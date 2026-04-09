#pragma once

#include "Solution.h"

class Data;

class Solver
{
public:
	Solver();

	virtual bool solve() = 0;

protected:
	const Data& data;

	Solution solution;
};
