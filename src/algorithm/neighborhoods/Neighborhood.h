#pragma once

class Data;
class Parameters;
class Solution;

class Neighborhood
{
public:
	Neighborhood();
	virtual ~Neighborhood() = default;

	virtual bool localSearch(Solution& solution) = 0;

	virtual bool randomMove(Solution& solution) = 0;

protected:
	const Data& data;
	const Parameters& params;
};
