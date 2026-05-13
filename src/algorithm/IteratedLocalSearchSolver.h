#pragma once

#include "AbstractSolver.h"

class Neighborhood;

class IteratedLocalSearchSolver : public AbstractSolver
{
public:
    IteratedLocalSearchSolver();
    ~IteratedLocalSearchSolver() override;

    bool solve(Solution& solution);
    bool solve() override;

private:
    std::vector<Neighborhood*> neighborhoods;
    Neighborhood* perturbation = nullptr;
};
