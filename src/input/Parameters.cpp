#include "Parameters.h"

#include <iostream>

using namespace std;

bool Parameters::load(const int argc, const char* argv[])
{
    if (argc < 2) return help("Not enough arguments");

    inputFile = string(argv[1]);

    return true;
}

bool Parameters::help(const string& msg)
{
    if (!msg.empty()) cout << "Error: " << msg << endl;
    cout << "Usage: tsp <input_file> [options]" << endl;
    cout << "Options:" << endl;
    cout << "  input_file: TSP instance file to solve." << endl;

    return false;
}