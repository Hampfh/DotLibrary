#include "Timing.h"

Timing::Timing(std::string optionalInput) : nameOfFunction(optionalInput){
	start = std::chrono::high_resolution_clock::now();
}


Timing::~Timing() {
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;

	std::cout << nameOfFunction << ": took " << duration.count() * 1000.0f << "ms" << std::endl;
}
