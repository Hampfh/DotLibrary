#include "window.h"
#include "text.h"
#include "Grid.h"

// Version 1.5

// The following values that main imports are very important
// without them SDL will give you an error
int main(int argc, char** argv) {

	Grid grid(3,3);
	grid.SetupWindow("Test window", 1000, 750);
	grid.visualize();
	while (true) {
		grid.mainWindow->clear();
	}

	return 0;
}

/*int main() {
	string temp;
	Grid myGrid(3,3);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	myGrid.visualize();
	while (true);
}*/