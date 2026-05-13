#include "Solution.h"

#include <format>
#include <iostream>

#include "input/Data.h"

using namespace std;

void Solution::evaluate()
{
	const Data& data = Data::getInstance();

	cost = 0;
	for (size_t i = 0; i < nodes.size() - 1; i++)
		cost += data.costs[nodes[i]][nodes[i + 1]];
}

ostream& operator<<(ostream& os, const Solution& solution)
{
	const Data& data = Data::getInstance();
	os << format("{} ({:.2f}%)", solution.cost, (solution.cost - data.bks) / static_cast<double>(data.bks) * 100.0);
	// os << format("{} ({:.4f})", solution.cost, (solution.cost/* - data.best*/) / static_cast<double>(data.bks));
	// for (size_t i = 0; i < solution.nodes.size(); i++) cout << solution.nodes[i] << ' ';
	// cout << endl;
	return os;
}
