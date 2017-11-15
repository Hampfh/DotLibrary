#include "Grid.h"

Dot::Dot(int xPos, int yPos) : _xPos(xPos), _yPos(yPos) {

}

Dot::~Dot() {

}

Grid::Grid(int width, int height){
	setup(width, height);
}


Grid::~Grid(){

}

// Code underneath creates the grid with all nodes and their coordinates
string Grid::setup(int width, int height) {
	// Initializing variables
		
	Origin = new Dot(0, 0);
	LastDot = nullptr;

	// Temporary pointers 
	Dot *currentDot = Origin;
	Dot *firstDotOfCurrentLine = Origin;
	Dot *prevDot = nullptr;
	Dot *currentDot_PrevLine = Origin;

	// Grid creation
	for (int currentyPos = 0; currentyPos < height; currentyPos++) {
		for (int currentxPos = 1; currentxPos < width; currentxPos++) {
			if (currentyPos > 0) {
				currentDot->RIGHT = new Dot(currentxPos, currentyPos);
				cout << "The new dot had x = " << currentxPos << " and y = " << currentyPos << endl;
				prevDot = currentDot;
				currentDot = currentDot->RIGHT;
				currentDot->LEFT = prevDot;

				// Connectiong current Dot with the Dot at the line above
				currentDot_PrevLine = currentDot_PrevLine->RIGHT;
				currentDot->UP = currentDot_PrevLine;
				currentDot_PrevLine->DOWN = currentDot;
			}
			else {
				currentDot->RIGHT = new Dot(currentxPos, currentyPos);
				cout << "The new dot had x = " << currentxPos << " and y = " << currentyPos << endl;
				prevDot = currentDot;
				currentDot = currentDot->RIGHT;
				currentDot->LEFT = prevDot;
			}
		}
		// Reset x cordinate for next level
		cout << "===============" << endl;
		if (currentyPos < height - 1) {
			// Reset the currentDot to the beginning of the line
			currentDot = firstDotOfCurrentLine;

			// CurrentDot creates a Dot underneath itself
			currentDot->DOWN = new Dot(0, currentyPos + 1);
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
		else {
			cout << "Line " << currentyPos << " was made successfully... --END--" << endl;
			LastDot = currentDot;
		}
	}
	return string();
}

void Grid::visualize() {
	Dot *currentDot = Origin;
	Dot *firstDotOfCurrentLine = Origin;
	cout << "Line " << Origin->_yPos << endl;
	while (currentDot != LastDot) {
		if (currentDot == Origin) {
			cout << "!";
		}
		if (currentDot->LEFT != nullptr) {
			cout << "<";
		}
		if (currentDot->UP != nullptr) {
			cout << "^";
		}
		if (currentDot->DOWN != nullptr) {
			cout << "V";
		}
		if (currentDot->RIGHT != nullptr) {
			cout << ">";
		}
		cout << "(" << currentDot->_xPos << " : " << currentDot->_yPos << ")";
		cout << " ";		

		if (currentDot->RIGHT == nullptr) {
			
			currentDot = firstDotOfCurrentLine;
			cout << endl;

			if (currentDot->DOWN != nullptr) {
				currentDot = currentDot->DOWN;
				firstDotOfCurrentLine = currentDot;
				cout << "Line " << currentDot->_yPos << endl;
			}
			else {
				cout << endl;
				cout << "Visulization done!" << endl;
				break;
			}
		}
		else {
			currentDot = currentDot->RIGHT;
		}
	} 


	// Code executes for the last node
	if (currentDot == Origin) {
		cout << "!";
	}
	if (currentDot->LEFT != nullptr) {
		cout << "<";
	}
	if (currentDot->UP != nullptr) {
		cout << "^";
	}
	if (currentDot->DOWN != nullptr) {
		cout << "V";
	}
	if (currentDot->RIGHT != nullptr) {
		cout << ">";
	}
	cout << "(" << currentDot->_xPos << " : " << currentDot->_yPos << ")";
	cout << " ";

	if (currentDot->RIGHT == nullptr) {

		currentDot = firstDotOfCurrentLine;
		cout << endl;

		if (currentDot->DOWN != nullptr) {
			currentDot = currentDot->DOWN;
			firstDotOfCurrentLine = currentDot;
		}
		else {
			cout << endl;
			cout << "Visulization done!" << endl;
		}
	}
	else {
		currentDot = currentDot->RIGHT;
	}
}
