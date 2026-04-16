#include "GraspSolver.h"

#include <vector>
#include <iostream>
#include <algorithm>

#include "Data.h"

#include "Random.h"

using namespace std;

bool GraspSolver::solve()
{
	for (int k = 0; k < 300'000; k++)
	{
		vector<bool> visited(data.dimension, false);

		Solution current;
		current.nodes.push_back(0);
		visited[0] = true;

		for (int _ = 1; _ < data.dimension; _++)
		{
			int last = current.nodes.back();
			vector<pair<int, int>> candidates;

			for (int j = 1; j < data.dimension; j++)
				if (!visited[j])
					candidates.push_back({ data.costs[last][j], j });
			sort(candidates.begin(), candidates.end());

			int next = candidates.front().second;;
			if (k > 0)
			{
				candidates.resize(min(3, (int)candidates.size()));
				next = Random::randomElem(candidates).second;
			}

			current.nodes.push_back(next);
			visited[next] = true;
		}
		current.nodes.push_back(0);
		current.evaluate();

		if (k == 0 || current.cost < solution.cost)
		{
			solution = current;
			cout << "Grasp: " << current << endl;
		}
	}

	return true;
}
