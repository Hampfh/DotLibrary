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
	Dot *prevDot = Origin;
	Dot *currentDot_PrevLine = Origin;

	// Grid creation
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			if (currentyPos > 0) {
				cout << ".";
				currentxPos++;
				currentDot_PrevLine = currentDot_PrevLine->RIGHT;
				currentDot->RIGHT = new Dot(currentxPos, currentyPos);
				prevDot = currentDot;
				currentDot = currentDot->RIGHT;
				currentDot->LEFT = prevDot;

				// Connectiong current Dot with the Dot at the line above
				//currentDot->UP = currentDot_PrevLine;
				//currentDot_PrevLine->DOWN = currentDot;

			}
			// This code only executes the at the first line
			else {
				cout << ".";
				currentxPos++;
				currentDot->RIGHT = new Dot(currentxPos, currentyPos);
				prevDot = currentDot;
				currentDot = currentDot->RIGHT;
				currentDot->LEFT = prevDot;
			}
		}
		currentxPos = 0;
		currentyPos++;
		if (currentyPos == height) {
			cout << "Line " << currentyPos << " was made successfully..." << endl;
			break;
		}

		currentDot->DOWN = new Dot(currentxPos, currentyPos);
		prevDot = currentDot;
		currentDot = currentDot->DOWN;
		currentDot = firstDotOfCurrentLine;
		currentDot_PrevLine = firstDotOfCurrentLine->UP;
		currentDot->UP = prevDot;
		cout << "Line " << currentyPos << " was made successfully..." << endl;
	}

	//delete currentDot;
	//delete firstDotOfCurrentLine;
	//delete prevDot;
	//delete currentDot_PrevLine;


	return string();
}
