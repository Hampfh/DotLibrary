#include "Text.h"
#include "font.h"

#include <iostream>

Text::Text()
{
}


Text::~Text()
{
}

void Text::drawText(Dot* startPointer, string text, int textSize) {
	Dot *currentDot = startPointer;
	string liveChar;
	bool running = true;
	
	for (int i = 0; i < int(text.length()); i++) {
		text[i] = tolower(text[i]);
		cout << "Currently doing: " << text[i] << endl;

		liveChar = _readInput(text[i]);
		Grid* currentLetterGrid = _letterGrid(liveChar[0] - '0');
		_drawText(currentLetterGrid->dot(0,0), liveChar);
		
		if (!_letterGridToGrid(currentDot, currentLetterGrid, 200, 0, 0, 0)) {
			break;
		}

		int characterLength = ((liveChar[0]) - '0') + 1;
		cout << "--" << endl;
		for (int j = 0; j < characterLength; j++) {
			if (currentDot->RIGHT == nullptr) {
				cout << "Found end of screen!" << endl;
				running = false;
				break;
			}
			else {
				cout << "I'm moving..." << endl;
				currentDot = currentDot->RIGHT;
			}
		}
		if (running == false) {
			cout << "I'm quiting" << endl;
			break;
		}
	}
}

string Text::_readInput(char letter) {
	int letterNum = int(letter) - int('a');
	return (DOTLIBRARY_FONT_DEFINITION[letterNum]);
}

Grid* Text::_letterGrid(int letterWidth) {
	Grid* thisLetter = new Grid(letterWidth, 5);
	return thisLetter;
}

void Text::_drawText(Dot* currentDot, string letterInstructions) {

	cout << "CurrentDot is: " << currentDot->xGridPosition << ":" << currentDot->yGridPosition << endl;

	int letterLength = letterInstructions.length();
	if (letterInstructions[0] != '#') {
		currentDot->color.r = 200;
		currentDot->color.g = 0;
		currentDot->color.b = 0;
		currentDot->draw();
	}

	for (int i = 0; i < letterLength; i++) {
		if (letterInstructions[i] == 'U' && currentDot->UP != nullptr) {
			currentDot = currentDot->UP;	
		}
		else if (letterInstructions[i] == 'R' && currentDot->RIGHT != nullptr) {
			currentDot = currentDot->RIGHT;
		}
		else if (letterInstructions[i] == 'D' && currentDot->DOWN != nullptr) {
			currentDot = currentDot->DOWN;
		}
		else if (letterInstructions[i] == 'L' && currentDot->LEFT != nullptr) {
			currentDot = currentDot->LEFT;
		}
		else if (i != 0) {
			break;
		}
		if (letterInstructions[i + 1] != '!' && letterInstructions[i] != '#') {
			currentDot->color.r = 200;
			currentDot->color.g = 0;
			currentDot->color.b = 0;
		}
		else if (letterInstructions[i + 1] == '!') {
			i++;
		}
	}
}

bool Text::_letterGridToGrid(Dot* mainGrid, Grid* letterGrid, int r, int g, int b, int a) {
	Dot* currentDotM = mainGrid;
	Dot* currentDotL = letterGrid->dot(0,0);
	Dot* firstDotOfCurrentLineM = currentDotM;
	Dot* firstDotOfCurrentLineL = currentDotL;

	cout << "Grid size: " << letterGrid->_gridLengthInDots << ":" << letterGrid->_gridHeightInDots << endl;

	while (currentDotL != letterGrid->LastDot) {
		cout << "The local dot is: " << currentDotL->xGridPosition << " and the global is: " << currentDotM->xGridPosition << endl;
		if (currentDotL->color.r == r && currentDotL->color.g == g && currentDotL->color.b == b && currentDotL->color.a == a) {
			currentDotM->color.r = currentDotL->color.r;
			currentDotM->color.g = currentDotL->color.g;
			currentDotM->color.b = currentDotL->color.b;
			currentDotM->color.a = currentDotL->color.a;
			currentDotM->draw();
		}
		
		//cout << "I'm drawing: " << currentDotM->xGridPosition << ":" << currentDotM->yGridPosition << endl;

		if (currentDotM->RIGHT == nullptr || currentDotL->RIGHT == nullptr) {

			currentDotL = firstDotOfCurrentLineL;
			currentDotM = firstDotOfCurrentLineM;

			if (currentDotM->DOWN != nullptr || currentDotL->DOWN != nullptr) {
				currentDotM = currentDotM->DOWN;
				firstDotOfCurrentLineM = currentDotM;

				currentDotL = currentDotL->DOWN;
				firstDotOfCurrentLineL = currentDotL;
			}
			else {
				return false;
			}
		}
		else {
			currentDotM = currentDotM->RIGHT;
			currentDotL = currentDotL->RIGHT;
		}
	}


	return true;
}