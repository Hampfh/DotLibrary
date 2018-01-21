#pragma once
#include <string>
#include "Window.h"
#include "Definitions.h"

class Dot {
private:
	Dot(int xPos, int yPos);
	~Dot();
public:
	/**
	@Desciption: Returns colorTemplate struct with RGB values
	@Return type: struct colorTemplate
	*/
	inline colorTemplate getColor() { return(_color); };
	/**
	@Desciption: Returns the size of the dot as a sizeTemplate struct
	@Return type: struct sizeTemplate
	*/
	inline sizeTemplate getSize() { return(_size); };
	/**
	@Desciption: Returns coordinateTemplate struct with x and y coordinates
	@Return type: struct coordinateTemplate
	*/
	inline coordinateTemplate getCoords() { return(_coordinates); };
	/**
	@Desciption: Returns coordinateTemplate struct with x and y coordinates. This value is the topleft pixel on the dot
	@Return type: struct coordinateTemplate
	*/
	inline coordinateTemplate getScreenCoords() { return(_screenCoordinates); };
	/**
	@Desciption: Set dot color by assigning RGB values. The function will return true if executed correctly otherwise false
	r minimum value is 0 : maximum value is 255
	g minimum value is 0 : maximum value is 255
	b minimum value is 0 : maximum value is 255
	@Return type: bool
	*/
	bool setColor(int r, int g, int b);
// Private functions
private:
	void draw();

// Private variables
private:
	friend class Grid;
	friend class Text;

	colorTemplate _color;
	sizeTemplate _size;
	coordinateTemplate _coordinates;
	coordinateTemplate _screenCoordinates;

	Dot *UP = nullptr;
	Dot *DOWN = nullptr;
	Dot *RIGHT = nullptr;
	Dot *LEFT = nullptr;
};

