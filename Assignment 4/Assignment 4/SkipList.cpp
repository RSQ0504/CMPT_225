#include "SkipList.h"
#include <iostream>

using namespace std;

SkipList::SkipList() : listHeads() {
    makeNewLevelList();
    makeNewLevelList();
}

// makes a new list on the top level of existing list.
// call only when top list is NULL or just the two sentinels. 
void SkipList::makeNewLevelList() {
    SkipList::Entry* minusInfinity = new Entry("!!", "");	// "!!" < any other string.
    SkipList::Entry* plusInfinity = new Entry("}}", "");	// "}}" > any other key.

    Quad* first = new Quad(minusInfinity);
    Quad* last = new Quad(plusInfinity);

    int numLists = listHeads.size();
    Quad* oldFirst = numLists == 0 ? NULL : listHeads[numLists - 1];
    Quad* oldLast  = numLists == 0 ? NULL : oldFirst->next;

    first->prev = NULL;
    first->next = last;
    first->above = NULL;
    first->below = oldFirst;

    last->prev = first;
    last->next = NULL;
    last->above = NULL;
    last->below = oldLast;

    if(oldFirst != NULL) {
        oldFirst->above = first;
        oldLast->above = last;
    }
    listHeads.push_back(first);
}

void SkipList::printOneList(int listNum) {
	Quad* bottomCurrent = listHeads[0];
	Quad* current = listHeads[listNum];

	while(bottomCurrent->next != NULL) {
		std::string toPrint;
		if(current->entry->getKey() == bottomCurrent->entry->getKey()) {
			toPrint = current->entry->getKey();
			current = current->next;
		}
		else {
			toPrint = "--";
		}
		cout << "--" << toPrint;
		bottomCurrent = bottomCurrent->next;
	}
	cout << "--" << bottomCurrent->entry->getKey() << "--" << endl;
}

void SkipList::print() {
	int numLists = listHeads.size();
	for(int i = numLists - 1; i >= 0; i--) {
		printOneList(i);
	}
} 

SkipList::Entry* SkipList::find(Key k) {
    int numLists = listHeads.size();
    Quad* current = listHeads[numLists - 1];

    while (current->below != NULL) {
        current = current->below;			// drop down
        while(k >= current->next->entry->getKey()) {	// scan forward
            current = current->next;
        }
    } 

    if(current->entry->key == k) {
        return current->entry;
    }
    else {
        return NULL;
    }
}

// the "trail" is a vector of the last node visited on each list
// the last element of trail is on the lowest list; the first is on the highest.
std::vector<SkipList::Quad*>* SkipList::findWithTrail(Key k) {
    std::vector<SkipList::Quad*>* trail = new std::vector<Quad*>();

    int numLists = listHeads.size();
    Quad* current = listHeads[numLists - 1];

    while (current != NULL) {
        while(k >= current->next->entry->getKey()) {	// scan forward
            current = current->next;
        }
        trail->push_back(current);
        current = current->below;			// drop down
    } 
    return trail;
}


// fill in the assigned functions here.

void SkipList::insert(Key k, Value v){
    int numLists = listHeads.size();
    Quad* current = listHeads[numLists - 1];

    while (current->below != NULL) {
        current = current->below;            // drop down
        while(k > current->next->entry->getKey()) {    // scan forward
            current = current->next;
        }
    }
    Entry *e=new Entry(k,v);
    Quad *n=new Quad(e);
    Quad *tempt=current->next;
    current->next=n;
    tempt->prev=n;
    n->below=NULL;
    n->above=NULL;
    n->prev=current;
    n->next=tempt;
    current=n;
    int b = std::rand()%2;
    int i=0;
    while(b){
        Quad* pre=current;
        b = std::rand()%2;
        i++;
        if(i>=numLists - 1){
            makeNewLevelList();
        }
        while(current->above==NULL){
            current=current->next;
        }
        current=current->above;
        Entry *e=new Entry(k,v);
        n=new Quad(e);
        pre->above=n;
        tempt=current->prev;
        current->prev=n;
        tempt->next=n;
        n->above=NULL;
        n->below=pre;
        n->prev=tempt;
        n->next=current;
        current=n;
    }
}
void SkipList::remove(Key k){
    int numLists = listHeads.size();
    int i=1;
    Quad* current = listHeads[numLists - 1];
    Quad* tempt;
    while (current->below != NULL) {
        current = current->below;            // drop down
        while(k >= current->next->entry->getKey()) {    // scan forward
            current = current->next;
        }
        if(current->entry->getKey()==k){
            i=0;
            while(current!=NULL){
                tempt=current;
                current->prev->next=current->next;
                current->next->prev=current->prev;
                if(current->below!=NULL)
                    current->below->above=NULL;
                current=current->below;
               if(tempt->next->next==NULL&&tempt->prev->prev==NULL){
                    listHeads.pop_back();
                    delete tempt->next->above->entry;
                    delete tempt->next->above;
                    delete tempt->prev->above->entry;
                    delete tempt->prev->above;
                }
                delete tempt->entry;
                delete tempt;
            }
            break;
        }
    }
    if(i){
        cout<<"Can not find"<<endl;
    }
}

SkipList::Entry* SkipList::ceilingEntry(Key k){
    if(find(k)!=NULL)
        return find(k);
    else{
    if(findWithTrail(k)->back()->next->next==NULL)
        return NULL;
    else{
        Entry* p=findWithTrail(k)->back()->next->entry;
        return p;
    }
    }
}
SkipList::Entry* SkipList::floorEntry(Key k){
    if(findWithTrail(k)->back()->prev==NULL)
        return NULL;
    else{
        Entry* p=findWithTrail(k)->back()->entry;
        return p;
    }
}
SkipList::Entry* SkipList::greaterEntry(Key k){
    if(find(k)==NULL){
        if(findWithTrail(k)->back()->next->next==NULL)
            return NULL;
        else{
            Entry*p=findWithTrail(k)->back()->next->entry;
            return p;
        }
    }else{
        if(findWithTrail(k)->back()->next->next==NULL)
            return NULL;
        else{
            Entry*p=findWithTrail(k)->back()->next->entry;
            return p;
        }
    }
}
SkipList::Entry* SkipList::lesserEntry(Key k){
    if(find(k)==NULL){
        if(findWithTrail(k)->back()->prev==NULL)
            return NULL;
        else{
            Entry* p=findWithTrail(k)->back()->entry;
            return p;
        }
    }else{
        if(findWithTrail(k)->back()->prev->prev==NULL)
            return NULL;
            else{
                Entry* p=findWithTrail(k)->back()->prev->entry;
                return p;
            }
    }
}

