#include "dot.h"

Dot::Dot(int xPos, int yPos) :
xGridPosition(xPos), yGridPosition(yPos)
{
	thisDot = new Rect();
}


Dot::~Dot(){

}

void Dot::callDrawMethod() {
	thisDot->draw(size.w, size.h, position.x, position.y, color.r, color.g, color.b, color.a);
}
