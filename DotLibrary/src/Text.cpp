#include "Text.h"

#include <iostream>

Text::Text(){
	_color.r = 254;
	_color.g = 254;
	_color.b = 254;
}


Text::~Text()
{
}

bool Text::_drawText() {
	_pixelLength = 0;
	_dotLength = 0;

	Dot *currentDot = referenseDot;
	std::string charInstructions;
	int charDotWidth;
	bool running = true;
	
	for (int i = 0; i < int(textContent.length()); i++) {
		textContent[i] = tolower(textContent[i]);

		// Get the character structure instructions
		charInstructions = _readInput(textContent[i]);

		// Gets width of character
		charDotWidth = charInstructions[0] - '0';

		// Prepare a grid
		Grid* currentLetterGrid = _letterGrid(charDotWidth);
		// Draws the character to the new grid
		_drawCharacter(currentLetterGrid->dot(0,0), charInstructions, _color);
		
		// Total text length addon
		_dotLength = _dotLength + charDotWidth + 1;

		_letterGridToGrid(currentDot, currentLetterGrid, _color);

		for (int j = 0; j < charDotWidth + 1; j++) {
			if (currentDot->RIGHT == nullptr) {
				running = false;
				break;
			}
			else {
				currentDot = currentDot->RIGHT;
			}
		}
		if (running == false) {
			return true;
		}
	}
	_pixelLength = _dotLength * referenseDot->getSize().w;
	return false;
}

std::string Text::_readInput(char letter) {
	int letterNum;
	
	// Special characters
	switch (letter) {
	case ':':
		letterNum = DOTLIB_FONT_CHAR_COLON;
		break;
	case ' ':
		letterNum = DOTLIB_FONT_CHAR_SPACE;
		break;
	case '.':
		letterNum = DOTLIB_FONT_CHAR_DOT;
		break;
	case ',':
		letterNum = DOTLIB_FONT_CHAR_COMMA;
		break;
	case '!':
		letterNum = DOTLIB_FONT_CHAR_EXCLAMATION;
		break;
	case '0':
		letterNum = DOTLIB_FONT_CHARINT_ZERO;
		break;
	default:
		// Character is a digit
		if (isdigit(letter))
			return DOTLIBRARY_FONT_DEFINITION[28 + (letter - '0')];
		// Character is a letter
		else
			letterNum = int(letter) - int('a');
		break;
	}
	return (DOTLIBRARY_FONT_DEFINITION[letterNum]);
}

Grid* Text::_letterGrid(int letterWidth) {
	Grid* thisLetter = new Grid(letterWidth, 5);
	return thisLetter;
}

void Text::_drawCharacter(Dot* currentDot, const std::string& letterInstructions, colorTemplate color) {

	int letterLength = letterInstructions.length();
	if (letterInstructions[1] != '#') {
		currentDot->setColor(color.r, color.g, color.b);
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
			currentDot->setColor(color.r, color.g, color.b);
		}
		else if (letterInstructions[i + 1] == '!') {
			i++;
		}
	}
}

bool Text::_letterGridToGrid(Dot* mainGrid, Grid* letterGrid, colorTemplate color) {
	Dot* currentDotM = mainGrid;
	Dot* currentDotL = letterGrid->dot(0,0);
	Dot* firstDotOfCurrentLineM = currentDotM;
	Dot* firstDotOfCurrentLineL = currentDotL;

	while (currentDotL != letterGrid->LastDot) {
		// Does not change color on transparent dots in the letterGrid
		if (currentDotL->getColor().r == color.r && currentDotL->getColor().g == color.g && currentDotL->getColor().b == color.b) {
			currentDotM->setColor(
				color.r, 
				color.g,
				color.b
			);
		}
		
		// If currentDot is nullptr then go back and draw next line
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
				delete letterGrid;
				return true;
			}
		}
		else {
			currentDotM = currentDotM->RIGHT;
			currentDotL = currentDotL->RIGHT;
		}
	}
	delete letterGrid;
	return false;
}

bool Text::setColor(int r, int g, int b) {
	if (r < 255 && r > -1 &&
		g < 255 && g > -1 && 
		b < 255 && b > -1) {
		_color.r = r;
		_color.g = g;
		_color.b = b;
		return(false);
	}
	else {
		_color.r = 254;
		_color.g = 254;
		_color.b = 254;
		return(true);
	}
}

void Text::drawText(Dot* startPointer, std::string text) {
	referenseDot = startPointer;
	textContent = text;
	_drawText();
}