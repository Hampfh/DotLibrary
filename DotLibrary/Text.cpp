#include "Text.h"

#include <iostream>

Text::Text()
{
}


Text::~Text()
{
}

void Text::drawText(Dot* startPointer, string text, int textSize) {
	Dot *currentDot = startPointer;
	
	for (int i = 0; i < text.length(); i++) {
		text[i] = tolower(text[i]);

		characters.live = _readInput(text[i]);
		_drawText(currentDot, characters.live);
		
		int characterLength = ((characters.live[0]) - '0') + 1;

		for (int j = 0; j < characterLength; j++) {
			if (currentDot->RIGHT == nullptr) {
				break;
			}
			else {
				currentDot = currentDot->RIGHT;
			}
		}
	}
}

// Private functions
string Text::_readInput(char letter) {
	cout << "this is the letters number: " << int(letter) << endl;
	if (letter == 'a') {
		characters.live = characters.a;
	}
	else if (letter == 'b') {
		characters.live = characters.b;
	}
	else if (letter == 'c') {
		characters.live = characters.c;
	}
	else if (letter == 'd') {
		characters.live = characters.d;
	}
	else if (letter == 'e') {
		characters.live = characters.e;
	}
	else if (letter == 'f') {
		characters.live = characters.f;
	}
	else if (letter == 'g') {
		characters.live = characters.g;
	}
	else if (letter == 'h') {
		characters.live = characters.h;
	}
	else if (letter == 'i') {
		characters.live = characters.i;
	}
	else if (letter == 'j') {
		characters.live = characters.j;
	}
	else if (letter == 'k') {
		characters.live = characters.k;
	}
	else if (letter == 'l') {
		characters.live = characters.l;
	}
	else if (letter == 'm') {
		characters.live = characters.m;
	}
	else if (letter == 'n') {
		characters.live = characters.n;
	}
	else if (letter == 'o') {
		characters.live = characters.o;
	}
	else if (letter == 'p') {
		characters.live = characters.p;
	}
	else if (letter == 'q') {
		characters.live = characters.q;
	}
	else if (letter == 'r') {
		characters.live = characters.r;
	}
	else if (letter == 's') {
		characters.live = characters.s;
	}
	else if (letter == 't') {
		characters.live = characters.t;
	}
	else if (letter == 'u') {
		characters.live = characters.u;
	}
	else if (letter == 'v') {
		characters.live = characters.v;
	}
	else if (letter == 'w') {
		characters.live = characters.w;
	}
	else if (letter == 'x') {
		characters.live = characters.x;
	}
	else if (letter == 'y') {
		characters.live = characters.y;
	}
	else if (letter == 'z') {
		characters.live = characters.z;
	}
	return characters.live;
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
		if (characters.live[i] == 'U' && currentDot->UP != nullptr) {
			currentDot = currentDot->UP;	
		}
		else if (characters.live[i] == 'R' && currentDot->RIGHT != nullptr) {
			currentDot = currentDot->RIGHT;
		}
		else if (characters.live[i] == 'D' && currentDot->DOWN != nullptr) {
			currentDot = currentDot->DOWN;
		}
		else if (characters.live[i] == 'L' && currentDot->LEFT != nullptr) {
			currentDot = currentDot->LEFT;
		}

		if (characters.live[i + 1] != '!' && characters.live[i] != '#') {
			currentDot->color.r = 200;
			currentDot->color.g = 0;
			currentDot->color.b = 0;
			currentDot->draw();
		}
		else if (characters.live[i + 1] == '!') {
			i++;
		}
	}
}