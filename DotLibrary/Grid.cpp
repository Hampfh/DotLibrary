#include "Grid.h"

Dot::Dot(int xPos, int yPos) : _xPos(xPos), _yPos(yPos) {

}

Dot::~Dot() {

}

Grid::Grid(){

}


Grid::~Grid(){

}

// Code underneath creates the grid with all nodes and their coordinates
string Grid::setup(int width, int height) {
	// Initializing variables
	int currentxPos = 0;
	int currentyPos = 0;
	Origin = new Dot(currentxPos, currentyPos);
	LastDot = Origin;

	// Temporary pointers 
	Dot *currentDot = Origin;
	Dot *firstDotOfCurrentLine = Origin;
	Dot *prevDot = nullptr;
	Dot *currentDot_PrevLine = Origin;

	// Grid creation
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			currentxPos++;
			currentDot->RIGHT = new Dot(currentxPos, currentyPos);
			prevDot = currentDot;
			currentDot = currentDot->RIGHT;
			currentDot->LEFT = prevDot;

			// Connectiong current Dot with the Dot at the line above
			currentDot_PrevLine = currentDot_PrevLine->RIGHT;
			currentDot->UP = currentDot_PrevLine;
			currentDot_PrevLine->DOWN = currentDot;
			cout << ".";
		}
		currentxPos = 0;
		currentyPos++;
		if (currentyPos == height) {
			cout << "Line " << currentyPos << " was made successfully... --END--" << endl;
			break;
		}

		// Reset the currentDot to the beginning of the line
		currentDot = firstDotOfCurrentLine;

		// CurrentDot creates a Dot underneath itself
		currentDot->DOWN = new Dot(currentxPos, currentyPos);
		prevDot = currentDot;

		// CurrentDot now moves down and connects with prevDot
		currentDot = currentDot->DOWN;
		currentDot->UP = prevDot;

		// FirstDotOfCurrentLine goes down one step to match the current y level
		firstDotOfCurrentLine = currentDot;

		// Now prevLine also resets to be one level up
		currentDot_PrevLine = firstDotOfCurrentLine->UP;
		cout << "Line " << currentyPos << " was made successfully..." << endl;
	}

	return string();
}
