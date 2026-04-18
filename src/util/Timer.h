#pragma once

#include <chrono>

class Timer
{
public:
	explicit Timer(bool started = true);

	void start();
	double lap();
	double stop();

	[[nodiscard]] double get() const { return total; }

private:
	std::chrono::time_point<std::chrono::system_clock> start_point;
	bool running;
	double total;
};
