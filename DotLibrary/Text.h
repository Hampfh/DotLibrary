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
	/**
	@Desciption: Draws the text class
	*/
	void drawText(Dot* startPointer, string text);
	/**
	@Desciption: Get the width of the text in dots
	@Return type: int
	*/
	inline int getDotLength() { return(_dotLength); };
	/**
	@Desciption: Returns colorTemplate struct with RGB values
	@Return type: struct colorTemplate
	*/
	inline colorTemplate getColor() { return(_color); };
	/**
	@Desciption: Set text color by assigning RGB values. The function will return true if executed correctly otherwise false
	r minimum value is 0 : maximum value is 255
	g minimum value is 0 : maximum value is 255
	b minimum value is 0 : maximum value is 255
	@Return type: bool
	*/
	bool setColor(int r, int g, int b);
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
