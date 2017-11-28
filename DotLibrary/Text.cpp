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

		liveChar = _readInput(text[i]);
		Grid* currentLetterGrid = _letterGrid(liveChar[0] - '0');
		_drawText(currentLetterGrid->dot(0,0), liveChar);
		
		if (!_letterGridToGrid(currentDot, currentLetterGrid, 200, 0, 0, 0)) {
			
		}

		int characterLength = ((liveChar[0]) - '0') + 1;
		cout << "--" << endl;
		for (int j = 0; j < characterLength; j++) {
			if (currentDot->RIGHT == nullptr) {
				running = false;
				break;
			}
			else {
				currentDot = currentDot->RIGHT;
			}
		}
		if (running == false) {
			break;
		}
	}
}

string Text::_readInput(char letter) {
	int letterNum;
	
	switch (letter) {
	case ' ':
		letterNum = CHAR_SPACE;
		break;
	default:
		letterNum = int(letter) - int('a');
		break;
	}
	return (DOTLIBRARY_FONT_DEFINITION[letterNum]);
}

Grid* Text::_letterGrid(int letterWidth) {
	Grid* thisLetter = new Grid(letterWidth, 5);
	return thisLetter;
}

void Text::_drawText(Dot* currentDot, string letterInstructions) {

	int letterLength = letterInstructions.length();
	if (letterInstructions[1] != '#') {
		currentDot->color.r = 200;
		currentDot->color.g = 0;
		currentDot->color.b = 0;
		currentDot->draw();
		cout << "MADE FIRST DOT" << endl;
	}

	for (int i = 1; i < letterLength; i++) {
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

	while (currentDotL != letterGrid->LastDot) {
		if (currentDotL->color.r == r && currentDotL->color.g == g && currentDotL->color.b == b && currentDotL->color.a == a) {
			currentDotM->color.r = currentDotL->color.r;
			currentDotM->color.g = currentDotL->color.g;
			currentDotM->color.b = currentDotL->color.b;
			currentDotM->color.a = currentDotL->color.a;
			currentDotM->draw();
		}
		
		if (currentDotM->RIGHT == nullptr || currentDotL->RIGHT == nullptr) {
			currentDotL = firstDotOfCurrentLineL;
			currentDotM = firstDotOfCurrentLineM;

			if (currentDotM->DOWN != nullptr && currentDotL->DOWN != nullptr) {
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