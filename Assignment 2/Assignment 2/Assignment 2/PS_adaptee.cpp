#include "PS_adaptee.h"
using namespace std;

PS_adaptee::PS_adaptee(ostream& o) : out(o) {
	out << "50 50 scale" << endl;
	out << "1 1 translate" << endl;
}
void PS_adaptee::setlinewidth(double width) {
	out << width << " setlinewidth" << endl;
}
void PS_adaptee::setrgbcolor(double r, double g, double b) {
	out << r << " " << g << " " << b << " setrgbcolor" << endl;
}
void PS_adaptee::gsave() {
	out << "gsave" << endl;
}
void PS_adaptee::grestore() {
	out << "grestore" << endl;
}
void PS_adaptee::stroke() {
	out << "stroke" << endl;
}
void PS_adaptee::fill() {
	out << "fill" << endl;
}
void PS_adaptee::newpath() {
	out << "newpath" << endl;
}
void PS_adaptee::closepath() {
	out << "closepath" << endl;
}
void PS_adaptee::showpage() {
	out << "showpage" << endl;
}
void PS_adaptee::moveto(double x, double y) {
	out << x << " " << y << " moveto" << endl;
}
void PS_adaptee::rmoveto(double x, double y) {
	out << x << " " << y << " rmoveto" << endl;
}
void PS_adaptee::lineto(double x, double y) {
	out << x << " " << y << " lineto" << endl;
}
void PS_adaptee::rlineto(double x, double y) {
	out << x << " " << y << " rlineto" << endl;
}
void PS_adaptee::arc(double x, double y, double rad, double theta1, double theta2) {
	out << x << " " << y << " " << rad << " " << theta1 << " " << theta2 << " arc" << endl;
}
