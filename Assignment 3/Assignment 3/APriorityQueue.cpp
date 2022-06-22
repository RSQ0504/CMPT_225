#include "APriorityQueue.h"
using namespace std;
APriorityQueue::APriorityQueue(){
    root=new Node();
}
APriorityQueue::Entry::Entry(const int& key,const string& value){
    this->k=key;
    this->v=value;
}
APriorityQueue::Entry::~Entry(){
    this->k=0;
    this->v="";
    node=NULL;
}
int APriorityQueue::Entry::key(){
    return this->k;
}
string APriorityQueue::Entry::value(){
    return this->v;
}
void APriorityQueue::Entry::setkey(int k){
    this->k=k;
    return;
}
void APriorityQueue::Entry::setvalue(string value){
    this->v=value;
    return;
}
APriorityQueue::Node::Node(){
    this->entry=NULL;
    this->parent=NULL;
    this->left=NULL;
    this->right=NULL;
}
APriorityQueue::Node::~Node(){
    delete left;
    delete right;
    entry=NULL;
    parent=NULL;
}
APriorityQueue::Entry& APriorityQueue::insert(int k, string v){
    Size++;
    if(root->entry==NULL){
        root->entry=new Entry(k,v);
        root->entry->node=root;
        last=root;
        return (*root->entry);
    }else if(root->left==NULL){
        Node* p=new Node();
        root->left=p;
        p->parent=root;
        p->entry=new Entry(k,v);
        p->entry->node=p;
        last=p;
        if(root->entry->key()>p->entry->key()){
            Node* t1;
            t1=p->entry->node;
            p->entry->node=root->entry->node;
            root->entry->node=t1;
            Entry* t2;
            t2=root->entry;
            root->entry=p->entry;
            p->entry=t2;
            return(*root->entry);
        }
        return (*p->entry);
    }else{
        Node* p=new Node();
        //find the area for inserting and insert and recond the area as "last"
        if(last->parent->right==NULL){
            last->parent->right=p;
            p->parent=last->parent;
        }else{
            if(last->parent==root){
                root->left->left=p;
                p->parent=root->left;
            }else if(last->parent->parent->right->left==NULL){
                last->parent->parent->right->left=p;
                p->parent=last->parent->parent->right;
            }else{
                Node* t=root;
                while(t->left!=NULL){
                    t=t->left;
                }
                t->left=p;
                p->parent=t;
            }
        }
        p->entry=new Entry(k,v);
        p->entry->node=p;
        last=p;
        //
        //sort
        while(p->entry->key()<p->parent->entry->key()){
            Node* t1;
            t1=p->entry->node;
            p->entry->node=p->parent->entry->node;
            p->parent->entry->node=t1;
            Entry* t2;
            t2=p->parent->entry;
            p->parent->entry=p->entry;
            p->entry=t2;
            p=p->parent;
            if(p->parent==NULL)
                break;
        }
        return (*p->entry);
    }
}
APriorityQueue::Entry& APriorityQueue::min(){
    return *root->entry;
}
int APriorityQueue::size(){
    return Size;
}
bool APriorityQueue::empty(){
    if(Size==0)
        return true;
    else
        return false;
}
void APriorityQueue::replace(Entry &e, int k, string v){
    Node *p=e.node;
    if(p==NULL)
        throw EntryNotFound("empty");
    e.setkey(0);
    e.setvalue("");
    e.node=NULL;
    delete p->entry;
    p->entry=new Entry(k,v);
    p->entry->node=p;
    while(1){
        if(p->left!=NULL&&p->right!=NULL&&p->entry->key()>p->left->entry->key()&&p->entry->key()>p->right->entry->key()){
        if(p->right->entry->key()<p->left->entry->key()){
            Node* t1;
            t1=p->entry->node;
            p->entry->node=p->right->entry->node;
            p->right->entry->node=t1;
            Entry* t2;
            t2=p->right->entry;
            p->right->entry=p->entry;
            p->entry=t2;
            p=p->right;
            if(p->left==NULL)
                break;
        }else{
            Node* t1;
            t1=p->entry->node;
            p->entry->node=p->left->entry->node;
            p->left->entry->node=t1;
            Entry* t2;
            t2=p->left->entry;
            p->left->entry=p->entry;
            p->entry=t2;
            p=p->left;
            if(p->left==NULL)
                break;
        }
    }else if(p->left!=NULL&&p->entry->key()>p->left->entry->key()){
            Node* t1;
            t1=p->entry->node;
            p->entry->node=p->left->entry->node;
            p->left->entry->node=t1;
            Entry* t2;
            t2=p->left->entry;
            p->left->entry=p->entry;
            p->entry=t2;
            p=p->left;
            if(p->left==NULL)
                break;
        }else if(p->right!=NULL&&p->entry->key()>p->right->entry->key()){
            Node* t1;
            t1=p->entry->node;
            p->entry->node=p->right->entry->node;
            p->right->entry->node=t1;
            Entry* t2;
            t2=p->right->entry;
            p->right->entry=p->entry;
            p->entry=t2;
            p=p->right;
            if(p->left==NULL)
                break;
        }else if(p->parent!=NULL&&p->entry->key()<p->parent->entry->key()){
            Node* t1;
            t1=p->entry->node;
            p->entry->node=p->parent->entry->node;
            p->parent->entry->node=t1;
            Entry* t2;
            t2=p->parent->entry;
            p->parent->entry=p->entry;
            p->entry=t2;
            p=p->parent;
            if(p->parent==NULL)
                break;
        }else
            break;
    }

    return;
}
void APriorityQueue::remove(Entry &e){
    Size--;
    Node *p=e.node;
    if(p==NULL)
        throw EntryNotFound("empty");
    e.setkey(0);
    e.setvalue("");
    e.node=NULL;
    delete p->entry;
    if(last==root)
        return;
    p->entry=new Entry(last->entry->key(),last->entry->value());
    p->entry->node=p;
    last->entry->setkey(0);
    last->entry->setvalue("");
    last->entry->node=NULL;
    
    if(last->parent->right!=NULL){
        last=last->parent->left;
        delete last->parent->right;
        last->parent->right=NULL;
    }else{
        Node *q=root;
        while(q->left!=NULL){
            q=q->left;
        }
        if(q==last){
            Node *n=root;
            while(n->right!=NULL){
                n=n->right;
            }
            last=n;
            q->parent->left=NULL;
            delete q;
        }else{
            if(last->parent==root){
                last=root;
                delete last->left;
                last->left=NULL;
            }else{
                last=last->parent->parent->left->right;
                delete last->parent->parent->right->left;
                last->parent->parent->right->left=NULL;
            }
        }
    }
    while(1){
        if(p->left!=NULL&&p->right!=NULL&&p->entry->key()>p->left->entry->key()&&p->entry->key()>p->right->entry->key()){
        if(p->right->entry->key()<p->left->entry->key()){
            Node* t1;
            t1=p->entry->node;
            p->entry->node=p->right->entry->node;
            p->right->entry->node=t1;
            Entry* t2;
            t2=p->right->entry;
            p->right->entry=p->entry;
            p->entry=t2;
            p=p->right;
            if(p->left==NULL)
                break;
        }else{
            Node* t1;
            t1=p->entry->node;
            p->entry->node=p->left->entry->node;
            p->left->entry->node=t1;
            Entry* t2;
            t2=p->left->entry;
            p->left->entry=p->entry;
            p->entry=t2;
            p=p->left;
            if(p->left==NULL)
                break;
        }
    }else if(p->left!=NULL&&p->entry->key()>p->left->entry->key()){
            Node* t1;
            t1=p->entry->node;
            p->entry->node=p->left->entry->node;
            p->left->entry->node=t1;
            Entry* t2;
            t2=p->left->entry;
            p->left->entry=p->entry;
            p->entry=t2;
            p=p->left;
            if(p->left==NULL)
                break;
        }else if(p->right!=NULL&&p->entry->key()>p->right->entry->key()){
            Node* t1;
            t1=p->entry->node;
            p->entry->node=p->right->entry->node;
            p->right->entry->node=t1;
            Entry* t2;
            t2=p->right->entry;
            p->right->entry=p->entry;
            p->entry=t2;
            p=p->right;
            if(p->left==NULL)
                break;
        }else if(p->parent!=NULL&&p->entry->key()<p->parent->entry->key()){
            Node* t1;
            t1=p->entry->node;
            p->entry->node=p->parent->entry->node;
            p->parent->entry->node=t1;
            Entry* t2;
            t2=p->parent->entry;
            p->parent->entry=p->entry;
            p->entry=t2;
            p=p->parent;
            if(p->parent==NULL)
                break;
        }else
            break;
    }
}
APriorityQueue::Entry& APriorityQueue::removeMin(){
    if(root->entry==NULL)
        throw(QueueEmpty("empty"));
    remove(this->min());
    return min();
}
APriorityQueue::~APriorityQueue(){
    while(!this->empty()){
        this->removeMin();
    }
    delete root;
    last=NULL;
    Size=0;
}
