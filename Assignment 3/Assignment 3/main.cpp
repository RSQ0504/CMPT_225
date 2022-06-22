#include<iostream>
#include<string>
#include "APriorityQueue.h"

using namespace std;

int main()
{
    try{
	APriorityQueue queue;
	cout << "inserting 3 and 4" <<endl; 
	queue.insert(3, "three");
	queue.insert(4, "four");
	cout << "Min is:" << queue.min().value() << endl; // This should print three
	cout << "Min removed. The new min is: " << queue.removeMin().value() << endl; //This should print four
	cout << "inserting 1 and 2" << endl;
	queue.insert(1, "one");
	queue.insert(2, "two");
	cout << "Min is:" << queue.min().value() << endl;// This should print one
	queue.replace (queue.min(), 3, "three");
	cout << "Min is:" << queue.min().value() << endl;//This should print two
	queue.insert(5, "five");
	while(!queue.empty()){
		cout << "The size is: " << queue.size() << " And the min is " << queue.min().value() << endl;
		queue.removeMin();
	}
    }catch (const QueueEmpty& e) {
        std::cout<<e.what();
    }catch (const EntryNotFound& e) {
        std::cout<<e.what();
    }
	return 0;	
}
