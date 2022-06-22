#pragma once
#include <iostream>

class PS_adaptee {
public:
	PS_adaptee(std::ostream& o);
	void setlinewidth(double width);
	void setrgbcolor(double r, double g, double b);
	void gsave();
	void grestore();
	void stroke();
	void fill();
	void newpath();
	void closepath();
	void showpage();
	void moveto(double x, double y);
	void rmoveto(double x, double y);
	void lineto(double x, double y);
	void rlineto(double x, double y);
	void arc(double x, double y, double rad, double theta1, double theta2);

private:
	std::ostream& out;
};

