#pragma once
#include "Dot.h"
#include "Grid.h"
#include "Definitions.h"
#include "font.h"

#include <string>
using namespace std;

class Text
{
//Public functions
public:
	Text();
	~Text();
	void setColor(int r, int g, int b, int a);
	void drawText(Dot* startPointer, string text);
// Private functions
private:
	string _readInput(char letter);
	Grid* _letterGrid(int letterWidth);
	void _drawText(Dot* startDot, string letterInstructions, colorTemplate color);
	bool _letterGridToGrid(Dot* mainGrid, Grid* letterGrid, colorTemplate color);
// Public variables
public:
	int dotLength;
	int pixelLength;

// Private variables
private:
	colorTemplate color;
};
