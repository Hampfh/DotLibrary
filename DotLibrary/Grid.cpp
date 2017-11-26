#include "Grid.h"

Grid::Grid(int width, int height) :
	_gridLengthInDots(width), _gridHeightInDots(height)
{
	setup(width, height);
}


Grid::~Grid(){

}

// Code underneath creates the grid with all dots and their coordinates
void Grid::setup(int width, int height) {
	// Initializing variables
		
	Origo = new Dot(0, 0);
	LastDot = nullptr;

	// Temporary pointers 
	Dot *currentDot = Origo;
	Dot *firstDotOfCurrentLine = Origo;
	Dot *prevDot = nullptr;
	Dot *currentDot_PrevLine = Origo;

	// Grid creation
	for (int currentyPos = 0; currentyPos < height; currentyPos++) {
		for (int currentxPos = 1; currentxPos < width; currentxPos++) {
			// All lines but the first is executed bellow
			if (currentyPos > 0) {
				currentDot->RIGHT = new Dot(currentxPos, currentyPos);
				prevDot = currentDot;
				currentDot = currentDot->RIGHT;
				currentDot->LEFT = prevDot;

				// Connectiong current Dot with the Dot at the line above
				currentDot_PrevLine = currentDot_PrevLine->RIGHT;
				currentDot->UP = currentDot_PrevLine;
				currentDot_PrevLine->DOWN = currentDot;
			}
			// First line i executed here
			else {
				currentDot->RIGHT = new Dot(currentxPos, currentyPos);
				prevDot = currentDot;
				currentDot = currentDot->RIGHT;
				currentDot->LEFT = prevDot;
			}
		}
		// Reset x cordinate for next level
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

		}
		else {
			currentDot->RIGHT = new Dot(currentDot->xGridPosition+1, currentyPos);
			LastDot = currentDot->RIGHT;
		}
	}
}

void Grid::visualize() {
	Dot *currentDot = Origo;
	Dot *firstDotOfCurrentLine = Origo;
	cout << "Line " << Origo->yGridPosition << endl;
	while (currentDot != LastDot) {
		if (currentDot == Origo) {
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
		cout << "(" << currentDot->xGridPosition << " : " << currentDot->yGridPosition << ")";
		cout << " ";		

		if (currentDot->RIGHT == nullptr) {
			
			currentDot = firstDotOfCurrentLine;
			cout << endl;

			if (currentDot->DOWN != nullptr) {
				currentDot = currentDot->DOWN;
				firstDotOfCurrentLine = currentDot;
				cout << "Line " << currentDot->yGridPosition << endl;
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
}

void Grid::drawDefaults() {
	Dot *currentDot = Origo;
	Dot *firstDotOfCurrentLine = Origo;

	int current_xPos = gridOffset.x;
	int current_yPos = gridOffset.y;
	
	// Origo setup
	Origo->position.x = current_xPos;
	Origo->position.y = current_yPos;
	Origo->size.w = dotSize;
	Origo->size.h = dotSize;
	Origo->color.r = color.r;
	Origo->color.g = color.g;
	Origo->color.b = color.b;
	Origo->color.a = color.a;
	Origo->draw();

	current_xPos = current_xPos + dotSize + spacing;

	currentDot = currentDot->RIGHT;

	while (currentDot != LastDot) {
		// Specifing properties for each dot
		currentDot->position.x = current_xPos;
		currentDot->position.y = current_yPos;
		currentDot->size.w = dotSize;
		currentDot->size.h = dotSize;
		currentDot->color.r = color.r;
		currentDot->color.g = color.g;
		currentDot->color.b = color.b;
		currentDot->color.a = color.a;
		
		current_xPos = current_xPos + dotSize + spacing;

		// Drawing the current dot to the screen
		currentDot->draw();

		if (currentDot->RIGHT == nullptr) {

			currentDot = firstDotOfCurrentLine;

			if (currentDot->DOWN != nullptr) {
				currentDot = currentDot->DOWN;
				firstDotOfCurrentLine = currentDot;
				current_xPos = gridOffset.x;
				current_yPos = current_yPos + dotSize + spacing;
			}
			else {
				cerr << "The requested dot was not found" << endl;
				break;
			}
		}
		else {
			currentDot = currentDot->RIGHT;
		}
	}
}

// Returns the requested dot to the user
Dot* Grid::dot(int xCord, int yCord) {
	Dot *currentDot = Origo;
	Dot *firstDotOfCurrentLine = Origo;

	if (xCord >= 0 && xCord < _gridLengthInDots && yCord >= 0 && yCord < _gridHeightInDots) {
		while (currentDot != LastDot) {
			if (currentDot->xGridPosition == xCord && currentDot->yGridPosition == yCord) {
				return currentDot;
			}

			if (currentDot->RIGHT == nullptr) {

				currentDot = firstDotOfCurrentLine;

				if (currentDot->DOWN != nullptr) {
					currentDot = currentDot->DOWN;
					firstDotOfCurrentLine = currentDot;
				}
				else {
					cerr << "The requested dot was not found" << endl;
					break;
				}
			}
			else {
				currentDot = currentDot->RIGHT;
			}
		}
		return nullptr;
	}
	else {
		cerr << "The dot specified is not in range and therefor Origo is returned as a dot";
		return Origo;
	}
}