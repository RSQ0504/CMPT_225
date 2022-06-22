#include "SimpleDisplay.h"
#include "PS_Display.h"
#include "Client.h"

int main() {

// uncomment one of the following two lines.   SimpleDisplay is provided with
// the starter code; PS_Display is what you have to write.
 
	//SimpleDisplay d(std::cout);
	PS_Display d(std::cout);

	Client client;

// uncomment one of the following two lines.  graph1 is a very simple picture,
// and graph2 is a little more complex.

	client.graph1(d);
	client.graph2(d);

	return(0);
}
