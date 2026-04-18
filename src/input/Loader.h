#pragma once

#include <string>
#include <fstream>

class Data;
class Parameters;

class Loader
{
public:
	Loader();

	bool load();

private:
	Data& data;
	const Parameters& params;

	std::ifstream fin;

	void readCoords();
	void buildEdges() const;
	void readBKS() const;
};
