/* 
 * File:   barista.h
 * Author: Cameron Gibson and John Zaidel
 *          gibso103            zaideljo
 *
 * header file for all classes related to project 2 of CSE335
 * 
 * Created on January 29, 2015, 4:46 PM
 */

#ifndef BARISTA_H
#define	BARISTA_H

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<algorithm>
using std::swap;
#include<iostream>
using std::cout;
#include "drink.h"

/****************************** OrderList *************************************/
class OrderList{
public:
    OrderList();
    OrderList(const OrderList &OL);
    OrderList& operator=(const OrderList &OL);
    virtual ~OrderList();
    virtual Drink* get_drink(int pos)=0;
    virtual int get_size()=0;
    virtual void swap_drinks(int d1,int d2, OrderList* OL)=0;
private:
	int sz;
};
/**************************** OrderList End ***********************************/

/**************************** BubbleTeaList ***********************************/
class BubbleTeaList:public OrderList{
public:
    BubbleTeaList(vector<BubbleTea*> &vec);
    BubbleTeaList(const BubbleTeaList &OL);
    BubbleTeaList& operator=(const BubbleTeaList &OL);
    virtual ~BubbleTeaList();
    virtual BubbleTea* get_drink(int pos);
    virtual int get_size();
    virtual void swap_drinks(int d1, int d2, OrderList* OL);
private:
    vector<BubbleTea*> ls;
};
/************************** BubbleTeaList End *********************************/

/************************ OrangeJuiceOrderList ********************************/
class OrangeJuiceOrderList:public OrderList{
public:
    OrangeJuiceOrderList(vector<OrangeJuice*> &vec);
    OrangeJuiceOrderList(const OrangeJuiceOrderList &OL);
    OrangeJuiceOrderList& operator=(const OrangeJuiceOrderList &OL);
    virtual ~OrangeJuiceOrderList();
    virtual OrangeJuice* get_drink(int pos);
    virtual int get_size();
    virtual void swap_drinks(int d1, int d2, OrderList* OL);
private:
    vector<OrangeJuice*> ls;
};
/********************** OrangeJuiceOrderList End ******************************/

/******************************** Barista *************************************/
class Barista{
public:
    Barista();
    Barista(const Barista &barista);
    Barista& operator=(const Barista &barista);
    virtual ~Barista();
    virtual void deliverDrinks(OrderList* OL);
};
/***************************** Barista End ************************************/

/***************************** CoolBarista ************************************/
class CoolBarista:public Barista{
public:
    CoolBarista();
    CoolBarista(const CoolBarista &barista);
    CoolBarista& operator=(const CoolBarista &barista);
    virtual ~CoolBarista();
    virtual void deliverDrinks(OrderList* OL);
};
/*************************** CoolBarista End **********************************/

/**************************** NewbieBarista ***********************************/
class NewbieBarista:public Barista{
public:
    NewbieBarista();
    NewbieBarista(const NewbieBarista &barista);
    NewbieBarista& operator=(const NewbieBarista &barista);
    virtual ~NewbieBarista();
    virtual void deliverDrinks(OrderList* OL);
};
/************************** NewbieBarista End *********************************/

#endif	/* BARISTA_H */