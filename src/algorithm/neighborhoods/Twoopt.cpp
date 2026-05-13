//
// Created by joao on 5/13/26.
//

#include "Twoopt.h"

#include <iostream>

#include "input/Data.h"
#include "output/Solution.h"
#include "util/Random.h"

using namespace std;

bool Twoopt::evaluate(const Solution& solution, Args& args) const
{
    const int prev = solution.nodes[args.pos1 - 1];
    const int curr0 = solution.nodes[args.pos1];
    const int curr1 = solution.nodes[args.pos2];
    const int next = solution.nodes[args.pos2 + 1];

    args.profit = data.costs[prev][curr0] + data.costs[curr1][next] -
        data.costs[prev][curr1] - data.costs[curr0][next];

    return true;
}

void Twoopt::move(Solution& solution, const Args& args)
{
    // cout << args.pos1 << " " << args.pos2 << endl;
    // solution.print_nodes();
    reverse(solution.nodes.begin()+args.pos1, solution.nodes.begin()+args.pos2+1);
    // solution.print_nodes();

    solution.evaluate();
}

bool Twoopt::localSearch(Solution& solution)
{
    bool any = false;
    bool found = true;
    while (found)
    {
        found = false;
        for (int pos1 = 1; pos1 < data.dimension - 2; pos1++)
            for (int pos2 = pos1 + 1; pos2 < data.dimension - 1; pos2++)
            {
                Args args(pos1, pos2);
                evaluate(solution, args);
                if (args.profit > 0)
                {
                    move(solution, args);
                    found = any = true;
                    cout << "[2Op] " << solution << endl;
                }
            }
    }
    return any;
}

bool Twoopt::randomMove(Solution& solution) {
    int pos = Random::randomInt(1, data.dimension - 2);
    int po2 = Random::randomInt(pos+1, data.dimension - 1);

    Args args(pos, po2);
    move(solution, args);

    cout << "[Rn2Op] " << solution << endl;
    return true;
}