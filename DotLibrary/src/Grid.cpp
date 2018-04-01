#include "Grid.h"

Grid::Grid(int width, int height)
{
	try {
		if (width < 0)
			throw width;
		else if (height < 0)
			throw height;
	}
	catch (int e) {
		std::cout << "ERROR: " << e << " is not a posetive number" << std::endl;
		throw;
	}
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
	Timer timer("GRID");
	Origo = new Dot(0, 0);
	// Temporary pointers 
	Dot *currentDot = Origo;
	Dot *firstDotOfCurrentLine = Origo;
	Dot *prevDot = nullptr;
	Dot *currentDot_PrevLine = Origo;

	// Grid creation
	for (int current_yPos = 0; current_yPos < height; current_yPos++) {
		for (int current_xPos = 1; current_xPos < width; current_xPos++) {
			// Create one line
			currentDot->RIGHT = new Dot(current_xPos, current_yPos);
			prevDot = currentDot;
			currentDot = currentDot->RIGHT;
			currentDot->LEFT = prevDot;

			// Does not run at the first line
			if (current_yPos > 0) {
				// Connectiong current Dot with the Dot at the line above
				currentDot_PrevLine = currentDot_PrevLine->RIGHT;
				currentDot->UP = currentDot_PrevLine;
				currentDot_PrevLine->DOWN = currentDot;
			}
		}
		// Create a new line underneath the current one
		if (current_yPos < height - 1) {
			// Reset the currentDot to the beginning of the line
			currentDot = firstDotOfCurrentLine;

			// CurrentDot creates a Dot underneath itself
			currentDot->DOWN = new Dot(0, current_yPos + 1);
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
			currentDot->RIGHT = new Dot(currentDot->getCoords().x + 1, current_yPos);
			LastDot = currentDot->RIGHT;
		}
	}
}

void Grid::clear() {
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

		current_xPos = current_xPos + _dotSize + _spacing;

		if (currentDot->RIGHT == nullptr) {

			currentDot = firstDotOfCurrentLine;

			if (currentDot->DOWN != nullptr) {
				currentDot = currentDot->DOWN;
				firstDotOfCurrentLine = currentDot;
				current_xPos = _offset.x;
				current_yPos = current_yPos + _dotSize + _spacing;
			}
			else {
				std::cerr << "The requested dot was not found" << std::endl;
				throw;
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
	Origo->draw();

	current_xPos = current_xPos + _dotSize + _spacing;

	currentDot = currentDot->RIGHT;

	while (currentDot != LastDot) {
		
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
				std::cerr << "The requested dot was not found" << std::endl;
				throw;
				break;
			}
		}
		else {
			currentDot = currentDot->RIGHT;
		}
	}
}

// Returns the requested dot to the user
Dot* Grid::dot(int xCoord, int yCoord) {
	Dot *currentDot = Origo;
	Dot *firstDotOfCurrentLine = Origo;

	if (xCoord >= 0 && xCoord < _gridSize.w && yCoord >= 0 && yCoord < _gridSize.h) {
		while (currentDot != LastDot) {
			if (currentDot->getCoords().x == xCoord && currentDot->getCoords().y == yCoord)
				return currentDot;

			if (currentDot->getCoords().x < xCoord)
				currentDot = currentDot->RIGHT;

			if (currentDot->getCoords().y < yCoord)
				currentDot = currentDot->DOWN;
		}
	}
	else {
		std::cerr << "ERROR: The dot specified is not in range and therefor Dot(0,0) is returned" << std::endl;
	}
	return Origo;
}

bool Grid::setOffset(int x, int y) {
	if (x >= 0 && y >= 0) {
		_offset.x = x;
		_offset.y = y;
		return(false);
	}
	else {
		return(true);
	}
}

bool Grid::setColor(int r, int g, int b) {
	if (r <= 255 && r >= 0 && g <= 255 && g >= 0 && b <= 255 && b >= 0) {
		_color.r = r;
		_color.g = g;
		_color.b = b;
		return(false);
	}
	else {
		return(true);
	}
}
bool Grid::setSpacing(int spacing) {
	if (spacing >= 0) {
		_spacing = spacing;
		return(false);
	}
	else {
		return(true);
	}
}

bool Grid::setDotSize(int dotSize) {
	if (dotSize >= 0) {
		_dotSize = dotSize;
		return(false);
	}
	else {
		return(true);
	}
}