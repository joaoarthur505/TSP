#include "AbstractSolver.h"

#include "input/Data.h"
#include "input/Parameters.h"

AbstractSolver::AbstractSolver() : data(Data::getInstance()), params(Parameters::getInstance()) {}
