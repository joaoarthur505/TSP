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
    std::vector<NeighborhoodType> neighborhoodTypes = {Shift, Swap};
    NeighborhoodType perturbationType = Swap;

    bool bestStart = false; // Só faz sentido se Nearest Neighbor é usado em algum momento

    int numIterations = 100;
private:
    static bool help(const std::string& msg = "");
};
