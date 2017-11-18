#include "dot.h"

Dot::Dot(int xPos, int yPos) :
	_xPos(xPos), _yPos(yPos)
{
	rect = new Rect(20, 20, 20, 20, 255, 255, 255, 255);
}


Dot::~Dot(){

}

void Dot::callDrawMethod() {

}
