#pragma once

#include <vector>
#include <ostream>

class Solution
{
public:
	int cost;
	std::vector<int> nodes;

	void evaluate();

	friend std::ostream& operator<<(std::ostream& os, const Solution& solution);
};
