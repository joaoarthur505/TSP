#include "Neighborhood.h"

#include "input/Data.h"
#include "input/Parameters.h"

Neighborhood::Neighborhood() : data(Data::getInstance()), params(Parameters::getInstance()) {}
