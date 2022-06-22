//
//  main.cpp
//  Assignment 1
//
//  Created by David Qian on 2021-09-25.
//

#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Animal{
private:
    int agemonth;
public:
    Animal();
    Animal(const int &n);
    virtual string noise();
    virtual int repeats();
    virtual int ageInMonths();
    virtual void print();
};
Animal::Animal(){
    agemonth=10;
}
Animal::Animal(const int &agemonth){
    this->agemonth=agemonth;
}
string Animal::noise(){
    string noise="grunt";
    return noise;
}
int Animal::repeats(){
    int r=3;
    return r;
}
int Animal::ageInMonths(){
    return agemonth;
}
void Animal::print(){
    int repeat=this->repeats();
    string n=this->noise();
    cout<<agemonth<<" ";
    for(int i=0;i<repeat;i++){
        cout<<n<<" ";
    }
}
class Cow:public Animal{
public:
    Cow();
    Cow(const int& age);
    virtual string noise();
    virtual int repeats();
};
Cow::Cow():Animal(){
}
Cow::Cow(const int &age):Animal(age){
}
string Cow::noise(){
    return "moo";
}
int Cow::repeats(){
    return 2;
}
class Cat:public Animal{
public:
    Cat();
    Cat(const int& age);
    virtual string noise();
    virtual int repeats();
};
Cat::Cat():Animal(){
}
Cat::Cat(const int &age):Animal(age){
}
string Cat::noise(){
    return "meow";
}
int Cat::repeats(){
    return 1;
}
class Duck:public Animal{
public:
    Duck();
    Duck(const int& age);
    virtual string noise();
    virtual int repeats();
};
Duck::Duck():Animal(){
}
Duck::Duck(const int &age):Animal(age){
}
string Duck::noise(){
    return "quack";
}
int Duck::repeats(){
    return 5;
}
class Sheep:public Animal{
public:
    Sheep();
    Sheep(const int& age);
    virtual string noise();
    virtual int repeats();
};
Sheep::Sheep():Animal(){
}
Sheep::Sheep(const int &age):Animal(age){
}
string Sheep::noise(){
    return "baa";
}
int Sheep::repeats(){
    return 4;
}
int main(){
    srand(time(nullptr));//use current time as a seed to creat random number.
    
/*
 create a variable(instance) of each class that you have defined (five variables total for this).
 */
    Animal a(rand()%100+0);//using random nember to give animals' age
    Cat b(rand()%100+0);//using random nember to give animals' age
    Cow c(rand()%100+0);//using random nember to give animals' age
    Duck d(rand()%100+0);//using random nember to give animals' age
    Sheep e(rand()%100+0);//using random nember to give animals' age
    a.print();
    cout<<endl;
    b.print();
    cout<<endl;
    c.print();
    cout<<endl;
    d.print();
    cout<<endl;
    e.print();
    cout<<endl;
    cout<<endl;
    
 
/*
 After that, declare an array of 10 pointers to Animals, and initialize each one with a type of animal. You should include instances of all the different subclasses and an instance of the superclass itself.
 */
    Animal **p=new Animal*[10];
    p[0]=new Animal();//Use the default age=10
    p[1]=new Cow();//Use the default age=10
    p[2]=new Cat();//Use the default age=10
    p[3]=new Duck();//Use the default age=10
    p[4]=new Sheep();//Use the default age=10
    p[5]=new Animal(rand()%100+0);//using random nember to give animals' age
    p[6]=new Cow(rand()%100+0);//using random nember to give animals' age
    p[7]=new Cat(rand()%100+0);//using random nember to give animals' age
    p[8]=new Duck(rand()%100+0);//using random nember to give animals' age
    p[9]=new Sheep(rand()%100+0);//using random nember to give animals' age
    for(int i=0;i<10;i++){
        p[i]->print();
        cout<<endl;
    }
    
//At the end of the program, delete all of the different animals that you allocated with new.
    for(int i=0;i<10;i++)
        delete [] p[i];
    delete [] p;

    return 0;
}
