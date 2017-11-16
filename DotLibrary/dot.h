#pragma once
#include <string>
#include "rect.h"
using namespace std;

class dot {
public:
	dot(const string &image_path);
	~dot();
private:
	void callDrawMethod();
private:
	Rect *graphicalDot;
};

