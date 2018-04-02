#pragma once
#include <chrono>
#include <iostream>
#include <string>

namespace DTL {

	class Timer {
	public:
		Timer(std::string optionalInput = "UNKNOWN");
		~Timer();
	private:
		std::string nameOfFunction;
		std::chrono::time_point<std::chrono::steady_clock> start, end;
		std::chrono::duration<float> duration;
	};

}