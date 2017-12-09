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
	void drawText(Dot* startPointer, string text);
	// Get function
	inline int getDotLength() { return(_dotLength); };
	inline colorTemplate getColor() { return(_color); };
	// Set function
	inline void setColor(int r, int g, int b) { _color.r = r, _color.g = g, _color.b = b; };
// Private functions
private:
	string _readInput(char letter);
	Grid* _letterGrid(int letterWidth);
	void _drawText(Dot* startDot, string letterInstructions, colorTemplate color);
	bool _letterGridToGrid(Dot* mainGrid, Grid* letterGrid, colorTemplate color);

// Private variables
private:
	int _dotLength;
	int _pixelLength;
	colorTemplate _color;
};
