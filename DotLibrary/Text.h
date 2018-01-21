#pragma once
#include "Dot.h"
#include "Grid.h"
#include "Definitions.h"
#include "font.h"
#include <string>

// forward declaration
class Grid;
class Dot;

class Text
{
//Public functions
public:
	Text();
	~Text();
	/**
	@Desciption: Draws a text string to a grid. The dot entered be in the top left
	*/
	void drawText(Dot* startDot, std::string text);
	/**
	@Desciption: Get the width of the text in dots
	@Return type: int
	*/
	inline int getDotLength() { return(_dotLength); };
	/**
	@Description: Get the text width in pixels
	@Return type: int
	*/
	inline int getPixelLength() { return(_pixelLength); };
	/**
	@Desciption: Returns colorTemplate struct with RGB values
	@Return type: struct colorTemplate
	*/
	inline colorTemplate getColor() { return(_color); };
	/**
	@Desciption: Set text color by assigning RGB values. The function will return true if executed correctly otherwise false
	r minimum value is 0 : maximum value is 254
	g minimum value is 0 : maximum value is 254
	b minimum value is 0 : maximum value is 254
	@Return type: bool
	*/
	bool setColor(int r, int g, int b);
// Private functions
private:
	std::string _readInput(char letter);
	Grid* _letterGrid(int letterWidth);
	void _drawText(); // Looping through the text string 
	void _drawCharacter(Dot* startDot, std::string letterInstructions, colorTemplate color); // Draws each character
	bool _letterGridToGrid(Dot* mainGrid, Grid* letterGrid, colorTemplate color); // Replicates the temp grid to the main grid

// Private variables
private:
	std::string textContent;
	Dot* referenseDot = nullptr;
	int _dotLength;
	int _pixelLength;
	colorTemplate _color;
};
