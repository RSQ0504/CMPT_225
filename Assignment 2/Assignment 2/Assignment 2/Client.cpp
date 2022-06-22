#include "Client.h"

void Client::graph1(Display& display) {
	display.start();
	display.color(Color::BLUE);
	display.width(1);
	display.edge(0.25, 0.25, 0.75, 0.25);
	display.shape(Shape::SQUARE);
	display.color(Color::RED);
	display.vertex(0.25, 0.25);
	display.vertex(0.75, 0.25);
	display.end();
}

void Client::graph2(Display& display) {
	display.start();

	display.color(Color::BLUE);
	display.width(5);
	display.edge(0.5, 0.8, 0.25, 0.6);
	display.edge(0.5, 0.8, 0.75, 0.6);
	display.shape(Shape::TRIANGLE);	
	display.color(Color::WHITE);
	display.vertex(0.5, 0.8);
	
	display.color(Color::GREEN);
	display.width(3);
	display.edge(0.25, 0.6, 0.125, 0.4);
	display.edge(0.25, 0.6, 0.375, 0.4);
	display.edge(0.75, 0.6, 0.875, 0.4);
	display.edge(0.75, 0.6, 0.625, 0.4);
	display.shape(Shape::CIRCLE);
	display.color(Color::BLACK);
	display.vertex(0.25, 0.6);
	display.vertex(0.75, 0.6);

	display.color(Color::RED);
	display.width(1);
	display.edge(0.125, 0.4, 0.0625, 0.2);
	display.edge(0.125, 0.4, 0.1875, 0.2);
	display.edge(0.375, 0.4, 0.3125, 0.2);
	display.edge(0.375, 0.4, 0.4375, 0.2);
	display.edge(0.875, 0.4, 0.8125, 0.2);
	display.edge(0.875, 0.4, 0.9375, 0.2);
	display.edge(0.625, 0.4, 0.5625, 0.2);
	display.edge(0.625, 0.4, 0.6875, 0.2);
	display.shape(Shape::SQUARE);
	display.color(Color::YELLOW);
	display.vertex(0.125, 0.4);
	display.vertex(0.375, 0.4);
	display.vertex(0.625, 0.4);
	display.vertex(0.875, 0.4);

	display.shape(Shape::TRIANGLE);
	display.color(Color::CYAN);
	display.vertex(0.0625, 0.2);
	display.vertex(0.1875, 0.2);
	display.vertex(0.3125, 0.2);
	display.vertex(0.4375, 0.2);
	display.vertex(0.8125, 0.2);
	display.vertex(0.9375, 0.2);
	display.vertex(0.5625, 0.2);
	display.vertex(0.6875, 0.2);

	
	display.end();
}