#include "Text.h"

#include <iostream>

Text::Text()
{
}


Text::~Text()
{
}

void Text::drawText() {
	_pixelLength = 0;
	_dotLength = 0;

	Dot *currentDot = referenseDot;
	std::string charInstructions;
	int charDotLength;
	bool running = true;
	
	for (int i = 0; i < int(textContent.length()); i++) {
		textContent[i] = tolower(textContent[i]);

		charInstructions = _readInput(textContent[i]);
		charDotLength = charInstructions[0] - '0';
		Grid* currentLetterGrid = _letterGrid(charDotLength);
		_drawText(currentLetterGrid->dot(0,0), charInstructions, _color);
		
		// Total text length addon
		_dotLength = _dotLength + charDotLength + 1;

		if (!_letterGridToGrid(currentDot, currentLetterGrid, _color)) {
			
		}

		for (int j = 0; j < charDotLength + 1; j++) {
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
	_pixelLength = _dotLength * referenseDot->getSize().w;
}

std::string Text::_readInput(char letter) {
	int letterNum;
	
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
	case '1':
		letterNum = DOTLIB_FONT_CHARINT_ONE;
		break;
	case '2':
		letterNum = DOTLIB_FONT_CHARINT_TWO;
		break;
	case '3':
		letterNum = DOTLIB_FONT_CHARINT_THREE;
		break;
	case '4':
		letterNum = DOTLIB_FONT_CHARINT_FOUR;
		break;
	case '5':
		letterNum = DOTLIB_FONT_CHARINT_FIVE;
		break;
	case '6':
		letterNum = DOTLIB_FONT_CHARINT_SIX;
		break;
	case '7':
		letterNum = DOTLIB_FONT_CHARINT_SEVEN;
		break;
	case '8':
		letterNum = DOTLIB_FONT_CHARINT_EIGHT;
		break;
	case '9':
		letterNum = DOTLIB_FONT_CHARINT_NINE;
		break;
	case '0':
		letterNum = DOTLIB_FONT_CHARINT_ZERO;
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

void Text::_drawText(Dot* currentDot, std::string letterInstructions, colorTemplate color) {

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
		if (currentDotL->getColor().r == color.r && currentDotL->getColor().g == color.g && currentDotL->getColor().b == color.b) {
			currentDotM->setColor(currentDotL->getColor().r, currentDotL->getColor().g, currentDotL->getColor().b);
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
				delete letterGrid;
				return false;
			}
		}
		else {
			currentDotM = currentDotM->RIGHT;
			currentDotL = currentDotL->RIGHT;
		}
	}
	delete letterGrid;
	return true;
}

bool Text::setColor(int r, int g, int b) {
	if (r <= 255 && r >= 0 && g <= 255 && g >= 0 && b <= 255 && b >= 0) {
		_color.r = r;
		_color.g = g;
		_color.b = b;
		return(true);
	}
	else {
		return(false);
	}
}

void Text::createText(Dot* startPointer, std::string text) {
	referenseDot = startPointer;
	textContent = text;
}