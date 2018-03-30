#pragma once
#include <chrono>
#include <iostream>
#include <string>

class Timing
{
public:
	Timing(std::string optionalInput = "UNKNOWN");
	~Timing();
private:
	std::string nameOfFunction;
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
};

