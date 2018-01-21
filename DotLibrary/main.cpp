#include "Grid.h"
#include "Window.h"
#include "Text.h"

int main(int argv, char** argc) {
	Window win("TEST", 800, 800);
	Grid gri(100, 100);
	gri.setSpacing(0);
	gri.setDotSize(5);
	gri.setColor(20, 20, 20);
	gri.drawDefaults();

	Text text;
	text.setColor(254, 255, 255);

	gri.dot(20, 20)->draw(60, 60, 60);

	text.drawText(gri.dot(20, 30), "TEST");

	win.refresh();

	while (true);

	return 1;
}