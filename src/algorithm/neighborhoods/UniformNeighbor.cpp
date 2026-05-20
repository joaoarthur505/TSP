//
// Created by joao on 5/20/26.
//

#include "UniformNeighbor.h"

#include <iostream>

#include "output/Solution.h"
#include "util/Random.h"

using namespace std;

bool UniformNeighbor::localSearch(Solution& solution) {
    return false;
}

bool UniformNeighbor::randomMove(Solution &solution) {
    Random::shuffle(solution.nodes.begin()+1, solution.nodes.end()-1);
    solution.evaluate();

    cout << "[RnNeigh] " << solution << endl;

    return true;
}
