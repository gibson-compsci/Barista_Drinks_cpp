/* 
 * File:   drink.h
 * Author: Cameron Gibson and John Zaidel
 *          gibso103            zaideljo
 *
 * header file for all classes related to project 1 of CSE335
 * 
 * Created on January 29, 2015, 4:46 PM
 */

#ifndef DRINK_H
#define	DRINK_H

#include<string>
using std::string;
#include<iostream>
using std::cout;

/*
 * Class Drink: Abstract base class
 *      -define attributes and methods that apply to all drinks
 *      -adds a useful switch_dsize method for switching the size
 *          from an integer to a string
 */

class Drink{
public:
    Drink(string cust, int size);
    Drink(const Drink &drink);
    Drink& operator= (const Drink &drink);
    //pure virtual function
    virtual ~Drink();
    virtual void confirmOrder()=0;
    static string switch_dsize(int size);
    virtual string get_name();
    virtual int get_size();
private:
    int d_size;
    string customer;
};

/*
 * Class BubbleTea: Subclass of the 'Drink' class
 *      -includes constructor, copy constructor, and operator=
 *          (uses default destructor because of simplicity)
 *      -defines specific attributes for BubbleTea (hot, bubble size)
 *      -specifies the confirmOrder method
 */

class BubbleTea:public Drink{
public:
    virtual void confirmOrder();
    BubbleTea(string name, int size, bool h, int b);
    BubbleTea(const BubbleTea& b);
    BubbleTea& operator=(const BubbleTea& b);
    virtual ~BubbleTea();
private:
    bool hot;
    string b_size;
};

/*
 * Class OrangeJuice: Subclass of the 'Drink' class
 *      -includes constructor, copy constructor, and assignment operator
 *          (uses default destructor because of simplicity)
 *      -defines specific attribute for pulp or no pulp
 *      -specifies the confirmOrder method
 */

class OrangeJuice:public Drink{
public:
    virtual void confirmOrder();
    OrangeJuice(string name, int size, bool p);
    OrangeJuice(const OrangeJuice& o);
    OrangeJuice& operator=(const OrangeJuice& o);
    virtual ~OrangeJuice();
private:
    bool pulp;
};

#endif	/* DRINK_H */