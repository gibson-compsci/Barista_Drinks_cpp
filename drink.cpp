/* 
 * File:   drink.cpp
 * Author: Cameron Gibson and John Zaidel
 *          gibso103            zaideljo
 *
 * cpp file for all classes related to project 1 of CSE335
 *      -contains implementations for all of the methods/constructors
 *          associated with the classes in drink.h
 * 
 * Created on January 29, 2015, 4:46 PM
 */

#include "drink.h" //include header file

Drink::Drink(string cust, int size){
    d_size=size;
    customer=cust;
}

Drink::Drink(const Drink& drink){
    d_size=drink.d_size;
    customer=drink.customer;
}

Drink& Drink::operator =(const Drink &drink){
    if(this!=&drink){
        d_size=drink.d_size;
        customer=drink.customer;
    }
    return *this;
}

Drink::~Drink(){}

/*
 * switch_dsize method that changes the size from integer to string
 */
string Drink::switch_dsize(int size) {
    string val;
    switch(size){
        case 1: val="small";
        break;
        case 2: val="medium";
        break;
        case 3: val="large";
        break;
        default: val="invalid size";
        break;
    }
    return val;
}

void Drink::confirmOrder(){
    cout<<customer<<" ordered a "<<switch_dsize(d_size)<<" drink";
}

string Drink::get_name(){
    return customer;
}

int Drink::get_size(){
    return d_size;
}

/*
 * constructor for BubbleTea class
 */
BubbleTea::BubbleTea(string name, int size, bool h, int b):Drink(name, size){
    hot=h;
    b_size=switch_dsize(b);
}

/*
 * copy constructor for BubbleTea class
 *      -pass as constant reference
 */
BubbleTea::BubbleTea(const BubbleTea& b):Drink(b){
    hot=b.hot;
    b_size=b.b_size;
}

/*
 * assignment operator for BubbleTea class
 *      -pass as constant reference
 */
BubbleTea& BubbleTea::operator =(const BubbleTea& b){
    if(this != &b){
        b_size=b.b_size;
        Drink::operator =(b);
    }
    return *this;
}

BubbleTea::~BubbleTea(){}

/*
 * confirmOrder method specifically for BubbleTea orders (prints order)
 */
void BubbleTea::confirmOrder(){
    Drink::confirmOrder();
    cout<<" of bubble tea with "<<b_size<<
            " bubbles";    
}

/*
 * constructor for OrangeJuice class
 */
OrangeJuice::OrangeJuice(string name, int size, bool p):Drink(name, size){
    pulp=p;
}

/*
 * copy constructor for OrangeJuice class
 *      -pass as constant reference
 */
OrangeJuice::OrangeJuice(const OrangeJuice& o):Drink(o){
    pulp=o.pulp;
}

/*
 * assignment operator for OrangeJuice class
 *      -pass as constant reference
 */
OrangeJuice& OrangeJuice::operator =(const OrangeJuice& o){
    if(this != &o){
        Drink::operator =(o);
        pulp=o.pulp;
    }
    return *this;
}

OrangeJuice::~OrangeJuice(){}

/*
 * confirmOrder method specifically for OrangeJuice orders (prints order)
 */
void OrangeJuice::confirmOrder(){
    Drink::confirmOrder();
    string yn="no pulp";
    if(pulp){yn="pulp";}
    cout<<" of orange juice with "<<yn;
}