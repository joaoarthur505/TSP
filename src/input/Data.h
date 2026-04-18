#pragma once

#include "util/Singleton.h"

#include <string>
#include <vector>

#include "util/Point.h"

class Data : public Singleton<Data>
{
	friend class Singleton;
public:
	Data(const Data&) = delete;
	Data& operator=(const Data&) = delete;

	std::string name;
	std::string type;
	int dimension = 0;

	int bks = 0;

	std::vector<Point> coords;
	std::vector<std::vector<int>> costs;

protected:
	Data() = default;
	~Data() = default;
};
