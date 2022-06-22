#pragma once
#include <iostream>
#include "Display.h"
#include "PS_adaptee.h"//"PS_adaptee.h"

class PS_Display: public Display {
	public:
    PS_Display(std::ostream& o);
    virtual void start();            // call to start a drawing
    virtual void color(Color col);    // all edges and vertices after this are this color
    virtual void shape(Shape s);    // all vertices after this are this shape
    virtual void width(int w);        // all edges after this are this width; all vertices bounding box is twice this width
    virtual void edge(double x1, double y1, double x2, double y2);        // draws an edge from (x1, y1) to (x2, y2)
    virtual void vertex(double x, double y);        // draws a vertex centered at x, y
    virtual void end();            // call to end the drawing
    virtual ~PS_Display() {};
	
    private:
    PS_adaptee *P;
    double w;
    Shape s;
    Color c;
};
