//
// Created by joao on 5/20/26.
//
#pragma once

#include "Neighborhood.h"

class Solution;

class UniformNeighbor : public Neighborhood
{
public:

    bool localSearch(Solution& solution) override;
    bool randomMove(Solution& solution) override;
};
