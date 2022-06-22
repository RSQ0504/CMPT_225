#pragma once
#include "Color.h"
#include "Shape.h"

class Display {
	public:
		virtual void start() = 0;			// call to start a drawing
		virtual void color(Color col) = 0;	// all edges and vertices after this are this color
		virtual void shape(Shape s) = 0;	// all vertices after this are this shape
		virtual void width(int w) = 0;		// all edges after this are this width; all vertices bounding box is twice this width
		virtual void edge(double x1, double y1, double x2, double y2) = 0;		// draws an edge from (x1, y1) to (x2, y2)
		virtual void vertex(double x, double y) = 0;		// draws a vertex centered at x, y
		virtual void end() = 0;			// call to end the drawing
		virtual ~Display() {};
};
