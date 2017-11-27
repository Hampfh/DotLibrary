#pragma once
#include "Dot.h"
#include <string>
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
	void _drawText(Dot* startDot, string letterInstructions);
};
