#pragma once

#include <vector>
#include <ostream>

class Solution
{
public:

	void evaluate();
	void print_nodes() const;
	friend std::ostream& operator<<(std::ostream& os, const Solution& solution);

	int cost = 0;
	std::vector<int> nodes;
};
