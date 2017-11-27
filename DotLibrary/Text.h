#pragma once
#include "Dot.h"
#include <string>
#include "Grid.h"
using namespace std;

class Text
{
//Public functions
public:
	Text();
	~Text();
	void drawText(Dot* startPointer, string text, int textSize);
// Private functions
private:
	string _readInput(char letter);
	Grid* _letterGrid(int letterWidth);
	void _drawText(Dot* startDot, string letterInstructions);
	bool _letterGridToGrid(Dot* mainGrid, Grid* letterGrid, int r, int g, int b, int a);
};
