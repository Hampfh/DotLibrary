#include "Grid.h"

Grid::Grid(int width, int height) :
	_gridLengthInDots(width), _gridHeightInDots(height)
{
	setup(width, height);
}


Grid::~Grid(){

}

// Code underneath creates the grid with all dots and their coordinates
string Grid::setup(int width, int height) {
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
	return string();
}

void Grid::SetupWindow(string title, int screenWidth, int screenHeight) {
	mainWindow = new Window(title, screenWidth, screenHeight);
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

void Grid::drawGrid() {
	Dot *currentDot = Origo;
	Dot *firstDotOfCurrentLine = Origo;

	int current_xPos = GridSpecifications.origo.x;
	int current_yPos = GridSpecifications.origo.y;
	
	Origo->position.x = current_xPos;
	Origo->position.y = current_yPos;
	Origo->size.w = GridSpecifications.dotSize;
	Origo->size.h = GridSpecifications.dotSize;
	Origo->color.r = GridSpecifications.color.r;
	Origo->color.g = 100;
	Origo->color.b = 100;
	Origo->color.a = GridSpecifications.color.a;
	Origo->callDrawMethod();

	current_xPos = current_xPos + GridSpecifications.dotSize + GridSpecifications.betweenDotDistance;

	currentDot = currentDot->RIGHT;

	while (currentDot != LastDot) {
		// Specifing properties for each dot
		currentDot->position.x = current_xPos;
		currentDot->position.y = current_yPos;
		currentDot->size.w = GridSpecifications.dotSize;
		currentDot->size.h = GridSpecifications.dotSize;
		currentDot->color.r = GridSpecifications.color.r;
		currentDot->color.g = GridSpecifications.color.g;
		currentDot->color.b = GridSpecifications.color.b;
		currentDot->color.a = GridSpecifications.color.a;
		
		current_xPos = current_xPos + GridSpecifications.dotSize + GridSpecifications.betweenDotDistance;

		// Drawing the current dot to the screen
		currentDot->callDrawMethod();

		if (currentDot->RIGHT == nullptr) {

			currentDot = firstDotOfCurrentLine;

			if (currentDot->DOWN != nullptr) {
				currentDot = currentDot->DOWN;
				firstDotOfCurrentLine = currentDot;
				current_xPos = GridSpecifications.origo.x;
				current_yPos = current_yPos + GridSpecifications.dotSize + GridSpecifications.betweenDotDistance;
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

Dot* Grid::specifyDot(int xCord, int yCord) {
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