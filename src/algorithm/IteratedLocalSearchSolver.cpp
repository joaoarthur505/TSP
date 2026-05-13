//
// Created by joao on 5/6/26.
//

#include "IteratedLocalSearchSolver.h"

#include <iostream>

#include "input/Parameters.h"

#include "neighborhoods/Neighborhood.h"
#include "neighborhoods/Shift.h"
#include "neighborhoods/Swap.h"
#include "neighborhoods/Twoopt.h"

#include "NearestNeighborSolver.h"

using namespace std;

IteratedLocalSearchSolver::IteratedLocalSearchSolver() {
    for (auto neighborhoodType : params.neighborhoodTypes) {
        switch (neighborhoodType)
        {
            case Parameters::Shift: neighborhoods.push_back(new Shift()); break;
            case Parameters::Swap: neighborhoods.push_back(new Swap()); break;
            case Parameters::Twoopt: neighborhoods.push_back(new Twoopt()); break;
            default: throw runtime_error("Unknown neighborhood type");
        }
    }

    switch (params.perturbationType)
    {
        case Parameters::Shift: perturbation = new Shift(); break;
        case Parameters::Swap: perturbation = new Swap(); break;
        case Parameters::Twoopt: perturbation = new Twoopt(); break;
        default: throw runtime_error("Unknown perturbation type");
    }
}

IteratedLocalSearchSolver::~IteratedLocalSearchSolver()
{
    for (const Neighborhood* neighborhood : neighborhoods)
        delete neighborhood;
    delete perturbation;
}

bool IteratedLocalSearchSolver::solve(Solution& solution) {
    Solution bestsolution = solution;

    for (int _ = 0; _ < params.numIterations; _++) {
        for (Neighborhood* neighborhood : neighborhoods)
            neighborhood->localSearch(solution);

        if (solution.cost < bestsolution.cost) {
            bestsolution = solution;
        }
        perturbation->randomMove(solution);
    }

    if (solution.cost < bestsolution.cost) {
        bestsolution = solution;
    }

    solution = bestsolution;
    cout << "IteratedLocalSearchSolver: " << solution << endl;
    return true;
}

bool IteratedLocalSearchSolver::solve() {
    NearestNeighborSolver nearest;
    nearest.solve();
    return solve(nearest.solution);
}