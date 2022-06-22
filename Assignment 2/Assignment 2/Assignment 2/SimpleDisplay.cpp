#include "SimpleDisplay.h"

using namespace std;

SimpleDisplay::SimpleDisplay(ostream& o) : out(o) {
}
void SimpleDisplay::start() {
	out << "start" << endl;
}
void SimpleDisplay::color(Color col) {
	out << "color " << col << endl;
}
void SimpleDisplay::shape(Shape s) {
	out << "shape " << s << endl;
}
void SimpleDisplay::width(int w) {
	out << "width " << w << endl;
}
void SimpleDisplay::edge(double x1, double y1, double x2, double y2) {
	out << "edge " << x1 << " " << y1 << " " << x2 << " " << y2 << endl; 
}
void SimpleDisplay::vertex(double x, double y) {
	out << "vertex " << x << " " << y << endl;
}
void SimpleDisplay::end() {
	out << "end" << endl;
}
SimpleDisplay::~SimpleDisplay() {
}

