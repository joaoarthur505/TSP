#pragma once

#include <string>
#include <vector>

#include "util/Singleton.h"

class Parameters : public Singleton<Parameters>
{
    friend class Singleton;
public:
    bool load(int argc, const char* argv[]);

    enum SolverType
    {
        GRASP,
        IteratedLocalSearch,
        NearestNeighbor,
        Random,
        VariableNeighborhoodDecent,
    };

    enum NeighborhoodType {
        Swap,
        Shift,
        Twoopt,
    };

    std::string inputFile = "data/eil101.tsp";
    SolverType solverType = IteratedLocalSearch;

    // ILS parameters:
    std::vector<NeighborhoodType> neighborhoodTypes = {Twoopt};
    NeighborhoodType perturbationType = Swap;
    int numIterations = 100;

    // NearestNeighbor Parameters
    bool bestStart = true; // Só faz sentido se Nearest Neighbor é usado em algum momento

private:
    static bool help(const std::string& msg = "");
};
