#include "Solution.h"

#include "Data.h"

void Solution::evaluate()
{
	const Data& data = Data::getBuilt();

	cost = 0;
	for (size_t i = 0; i < nodes.size() - 1; i++)
		cost += data.costs[nodes[i]][nodes[i + 1]];
}
