
#include "PS_Display.h"

using namespace std;

PS_Display::PS_Display(std::ostream& o){
    this->P=new PS_adaptee(o);
}
void PS_Display::start(){
    P->setrgbcolor(0.8, 0.8, 0.8);
    P->newpath();
    P->moveto(0, 0);
    P->lineto(0, 10);
    P->lineto(10, 10);
    P->lineto(10, 0);
    P->lineto(0, 0);
    P->closepath();
    P->fill();
    P->stroke();
    return;
}            // call to start a drawing
/*
RED
GREEN,
BLUE,
CYAN,
MAGENTA,
YELLOW,
WHITE,
BLACK
 */
void PS_Display::color(Color col){
    switch(col){
        case 0: P->setrgbcolor(1, 0, 0); break;
        case 1: P->setrgbcolor(0, 1, 0); break;
        case 2: P->setrgbcolor(0, 0, 1); break;
        case 3: P->setrgbcolor(0, 1, 1); break;
        case 4: P->setrgbcolor(1, 0, 1); break;
        case 5: P->setrgbcolor(1, 1, 0); break;
        case 6: P->setrgbcolor(1, 1, 1); break;
        case 7: P->setrgbcolor(0, 0, 0); break;
    }
    this->c=col;
    return;
}   // all edges and vertices after this are this color
void PS_Display::shape(Shape s){
    this->s=s;
    return;
}   // all vertices after this are this shape
void PS_Display::width(int w){
    this->w=0.03*w;
    return;
}     // all edges after this are this width; all vertices bounding box is twice this width
void PS_Display::edge(double x1, double y1, double x2, double y2){
    x1=x1*10;
    x2=x2*10;
    y1=y1*10;
    y2=y2*10;
    P->newpath();
    P->moveto(x1, y1);
    P->setlinewidth(w);
    P->lineto(x2, y2);
    P->closepath();
    P->stroke();
    return;
}      // draws an edge from (x1, y1) to (x2, y2)
void PS_Display::vertex(double x, double y){
    x=x*10;
    y=y*10;
    switch (s) {
        case CIRCLE:
            P->newpath();
            P->arc(x, y, 2*w, 0, 360);
            P->closepath();
            P->fill();
            P->stroke();
            break;
        case TRIANGLE:
            P->newpath();
            P->moveto(x, y+2*w);
            P->lineto(x+2*w, y-2*w);
            P->lineto(x-2*w, y-2*w);
            P->lineto(x, y+2*w);
            P->closepath();
            P->fill();
            P->stroke();
            break;
        case SQUARE:
            P->newpath();
            P->moveto(x-2*w, y+2*w);
            P->lineto(x+2*w, y+2*w);
            P->lineto(x+2*w, y-2*w);
            P->lineto(x-2*w, y-2*w);
            P->lineto(x-2*w, y+2*w);
            P->closepath();
            P->fill();
            P->stroke();
            break;
    }
    return;
}        // draws a vertex centered at x, y
void PS_Display::end(){
    P->showpage();
    return;
}            // call to end the drawin
