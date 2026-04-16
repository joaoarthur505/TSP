#pragma once

#include "Singleton.h"

#include <string>
#include <vector>

#include "Point.h"

class Data : public Singleton<Data>
{
	friend class Singleton<Data>;
public:
	std::string name;
	std::string type;
	int dimension;

	int bks;

	std::vector<Point> coords;
	std::vector<std::vector<int>> costs;

protected:
	Data() = default;
	~Data() = default;

	Data(const Data&) = delete;
	Data& operator=(const Data&) = delete;
};
