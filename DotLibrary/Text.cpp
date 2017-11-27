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
		_drawText(currentDot, liveChar);
		
		int characterLength = ((liveChar[0]) - '0') + 1;

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
			cout << "I'm quiting" << endl;
			break;
		}
	}
}

string Text::_readInput(char letter) {
	int letterNum = int(letter) - int('a');
	return (DOTLIBRARY_FONT_DEFINITION[letterNum]);
}

void Text::_drawText(Dot* currentDot, string letterInstructions) {

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

		if (letterInstructions[i + 1] != '!' && letterInstructions[i] != '#') {
			currentDot->color.r = 200;
			currentDot->color.g = 0;
			currentDot->color.b = 0;
			currentDot->draw();
		}
		else if (letterInstructions[i + 1] == '!') {
			i++;
		}
	}
}