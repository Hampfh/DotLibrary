#include "Grid.h"

Grid::Grid(int width, int height)
{
	_gridSize.w = width;
	_gridSize.h = height;
	setup(width, height);
}


Grid::~Grid(){
	//visualize();
	Dot* currentDot = Origo;
	Dot* prevDot = Origo;
	Dot* firstDotOfCurrentLine = currentDot->DOWN;

	while (currentDot != LastDot) {
		if (currentDot->RIGHT == nullptr) {

			prevDot = currentDot;
			currentDot = firstDotOfCurrentLine;
			delete prevDot;

			if (currentDot->DOWN != nullptr) {
				firstDotOfCurrentLine = currentDot->DOWN;
			}
		}
		else {
			prevDot = currentDot;
			currentDot = currentDot->RIGHT;
			delete prevDot;
		}
	}
	delete LastDot;
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
			currentDot->RIGHT = new Dot(currentDot->getCoords().x + 1, currentyPos);
			LastDot = currentDot->RIGHT;
		}
	}
}

void Grid::visualize() {
	Dot *currentDot = Origo;
	Dot *firstDotOfCurrentLine = Origo;
	cout << "Line " << Origo->getCoords().y << endl;
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
		cout << "(" << currentDot->getCoords().x << " : " << currentDot->getCoords().y << ")";
		cout << " ";		

		if (currentDot->RIGHT == nullptr) {
			
			currentDot = firstDotOfCurrentLine;
			cout << endl;

			if (currentDot->DOWN != nullptr) {
				currentDot = currentDot->DOWN;
				firstDotOfCurrentLine = currentDot;
				cout << "Line " << currentDot->getCoords().y << endl;
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

	int current_xPos = _offset.x;
	int current_yPos = _offset.y;
	
	// Origo setup
	Origo->_screenCoordinates.x = current_xPos;
	Origo->_screenCoordinates.y = current_yPos;
	Origo->_size.w = _dotSize;
	Origo->_size.h = _dotSize;
	Origo->_color.r = _color.r;
	Origo->_color.g = _color.g;
	Origo->_color.b = _color.b;
	Origo->_color.a = _color.a;
	Origo->draw();

	current_xPos = current_xPos + _dotSize + _spacing;

	currentDot = currentDot->RIGHT;

	while (currentDot != LastDot) {
		// Specifing properties for each dot
		currentDot->_screenCoordinates.x = current_xPos;
		currentDot->_screenCoordinates.y = current_yPos;
		currentDot->_size.w = _dotSize;
		currentDot->_size.h = _dotSize;
		currentDot->_color.r = _color.r;
		currentDot->_color.g = _color.g;
		currentDot->_color.b = _color.b;
		currentDot->_color.a = _color.a;
		
		current_xPos = current_xPos + _dotSize + _spacing;

		// Drawing the current dot to the screen
		currentDot->draw();

		if (currentDot->RIGHT == nullptr) {

			currentDot = firstDotOfCurrentLine;

			if (currentDot->DOWN != nullptr) {
				currentDot = currentDot->DOWN;
				firstDotOfCurrentLine = currentDot;
				current_xPos = _offset.x;
				current_yPos = current_yPos + _dotSize + _spacing;
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
	
	if (xCord >= 0 && xCord < _gridSize.w && yCord >= 0 && yCord < _gridSize.h) {
		while (currentDot != LastDot) {
			if (currentDot->getCoords().x == xCord && currentDot->getCoords().y == yCord) {
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