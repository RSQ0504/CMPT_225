#pragma once
#include <iostream>
#include "Display.h"

class SimpleDisplay : public Display {
	public:
		SimpleDisplay(std::ostream& o);
		virtual void start();
		virtual void color(Color col);
		virtual void shape(Shape s);
		virtual void width(int w);
		virtual void edge(double x1, double y1, double x2, double y2);
		virtual void vertex(double x, double y);
		virtual void end();
		virtual ~SimpleDisplay();
	private:
		std::ostream& out;
};

