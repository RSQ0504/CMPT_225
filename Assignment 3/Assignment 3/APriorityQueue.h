#pragma once
#include<string>
#include "QueueEmpty.h"
#include "EntryNotFound.h"
using namespace std;


class APriorityQueue
{
	public:
    class Node;
	class Entry{
		public:
        Entry(const int& key,const string& value);
        ~Entry();
		int key();
		string value();
        void setvalue(string value);
        void setkey(int k);
        Node* node;
		
		private:
		int k;
		string v;
	};
    class Node{
    public:
        Node();
        ~Node();
        Node* left;
        Node* right;
        Node* parent;
        Entry* entry;
    };
	APriorityQueue();
	~APriorityQueue();
	Entry& insert(int k, string v);
	Entry& removeMin();
	Entry& min();
	void remove(Entry& e);
	void replace(Entry& e, int k, string v);
	int size();
	bool empty();
    
	private:
    Node* root;
    Node* last;
    int Size=0;
};

