#pragma once
#include <iostream>
#include "Dot.h"
#include "Definitions.h"
#include "Text.h"
#include "Timer.h"

namespace DTL {

	// Forward declaration
	class Dot;

	class Grid {
	public:
		Grid(int width, int height);
		~Grid();
		/**
		@Description: Sets all grid values to what's specified
		@Return type: void
		*/
		void clear();
		/**
		@Desciption: Returns a requested dot by passing in an x and y coordinate.
		@Return type: Dot*
		*/
		Dot* dot(int xCoord, int yCoord);
	private:
		friend class Text;
		friend class Window;
		void setup(int width, int height);
		void drawDefaults();
	public:
		/**
		@Desciption: Returns the size of the grid as a sizeTemplate struct
		@Return type: struct sizeTemplate
		*/
		inline sizeTemplate getGridSize() { return(_gridSize); };
		/**
		@Desciption: Returns coordinateTemplate struct with x and y offset
		@Return type: struct coordinateTemplate
		*/
		inline coordinateTemplate getOffset() { return(_offset); };
		/**
		@Desciption: Returns colorTemplate struct with RGB values
		@Return type: struct colorTemplate
		*/
		inline colorTemplate getColor() { return(_color); };
		/**
		@Desciption: Returns int value representing spacing between each dot in the grid
		@Return type: int
		*/
		inline int getSpacing() { return(_spacing); };
		/**
		@Desciption: Returns int value
		@Return type: int
		*/
		inline int getDotSize() { return(_dotSize); };

		/**
		@Desciption: Set grid offset values. The function will return true if executed correctly otherwise false
		x minimum value is 0
		y minimum value is 0
		@Return type: bool
		*/
		bool setOffset(int x, int y);
		/**
		@Desciption: Set grid color by assigning RGB values. The function will return true if executed correctly otherwise false
		r minimum value is 0 : maximum value is 255
		g minimum value is 0 : maximum value is 255
		b minimum value is 0 : maximum value is 255
		@Return type: bool
		*/
		bool setColor(int r, int g, int b);
		/**
		@Desciption: Set a spacing distance between all dots. The function will return true if executed correctly otherwise false
		x minimum value is 0
		y minimum value is 0
		@Return type: bool
		*/
		bool setSpacing(int spacing);
		/**
		@Desciption: Size of each dot. The function will return true if executed correctly otherwise false
		x minimum value is 0
		y minimum value is 0
		@Return type: bool
		*/
		bool setDotSize(int dotSize);
	private:
		Dot *Origo = nullptr;
		Dot *LastDot = nullptr;
		sizeTemplate _gridSize;

		// Changeble variables
		int _spacing = 10;
		int _dotSize = 15;
		coordinateTemplate _offset;
		colorTemplate _color;

		Grid* next = nullptr;
	};

}