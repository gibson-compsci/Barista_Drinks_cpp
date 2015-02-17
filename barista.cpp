/* 
 * File:   barista.cpp
 * Author: Cameron Gibson and John Zaidel
 *          gibso103            zaideljo
 *
 * cpp file for barista.h classes related to project 2 of CSE335
 *      -contains implementations for all of the methods/constructors
 *          associated with the classes in barista.h
 * 
 * Created on January 29, 2015, 4:46 PM
 */

#include "barista.h"

/****************************** OrderList *************************************/
OrderList::OrderList(){}

OrderList::OrderList(const OrderList& OL){}

OrderList& OrderList::operator =(const OrderList& OL){
    return *this;
}

OrderList::~OrderList(){}
/**************************** OrderList End ***********************************/

/**************************** BubbleTeaList ***********************************/
BubbleTeaList::BubbleTeaList(vector<BubbleTea*>& vec){
    ls=vec;
}

int BubbleTeaList::get_size(){
    return ls.size();
}

void BubbleTeaList::swap_drinks(int d1, int d2, OrderList* OL){
    swap(ls[d2], ls[d1]);
}

BubbleTea* BubbleTeaList::get_drink(int pos){
    return ls[pos];
}

BubbleTeaList::~BubbleTeaList(){}
/************************** BubbleTeaList End *********************************/

/************************ OrangeJuiceOrderList ********************************/
OrangeJuiceOrderList::OrangeJuiceOrderList(vector<OrangeJuice*>& vec){
    ls=vec;
}

int OrangeJuiceOrderList::get_size(){
    return ls.size();
}

void OrangeJuiceOrderList::swap_drinks(int d1, int d2, OrderList* OL){
    swap(ls[d2], ls[d1]);
}

OrangeJuice* OrangeJuiceOrderList::get_drink(int pos){
    return ls[pos];
}

OrangeJuiceOrderList::~OrangeJuiceOrderList(){}
/********************** OrangeJuiceOrderList End ******************************/

/******************************** Barista *************************************/
Barista::Barista(){}

Barista::Barista(const Barista &barista){}
    
Barista& Barista::operator=(const Barista &barista){
    return *this;
}

void Barista::deliverDrinks(OrderList* OL){
    for(unsigned int i=0; i<OL->get_size(); i++){
        Drink* current=OL->get_drink(i);
        current->confirmOrder();
    }
}
    
Barista::~Barista(){}
/***************************** Barista End ************************************/

/***************************** CoolBarista ************************************/
CoolBarista::CoolBarista(){}

CoolBarista::CoolBarista(const CoolBarista &barista){}
    
CoolBarista& CoolBarista::operator=(const CoolBarista &barista){
    return *this;
}

void CoolBarista::deliverDrinks(OrderList* OL)
{
//    cout << OL->get_drink(0)->get_name() << OL->get_drink(1)->get_name() << 
//                OL->get_drink(2)->get_name() << OL->get_drink(3)->get_name() << 
//                OL->get_drink(4)->get_name() << "\n";
    // Insertion Sort sorts every next element in order.

    // Loops through the whole vector
    for (unsigned int i = 1; i < OL->get_size(); i++)
    {
        int j = i;
        //cout<<first_drink->get_name()<<second_drink->get_name()<<"\n";
		
        // Compares vec[1] to vec[0] (respectively) depending on the desired order
        while (j > 0)
        {
            string first_name = OL->get_drink(j-1)->get_name();
            string second_name = OL->get_drink(j)->get_name();
            //cout << first_name << second_name << "\n";
            if (first_name > second_name)
            {
                OL->swap_drinks(j, (j-1), OL);
            }
            j--;
        }
    }
//    cout << OL->get_drink(0)->get_name() << OL->get_drink(1)->get_name() << 
//                OL->get_drink(2)->get_name() << OL->get_drink(3)->get_name() << 
//                OL->get_drink(4)->get_name() << "\n";
    cout<<"Cool Barista: Order's up!\n";
    vector<Drink*> same_name;
    for (unsigned int i = 0; i < OL->get_size();)
    {
        int j=i+1;
        int num_drinks=1;
        same_name.push_back(OL->get_drink(i));
        if(j<OL->get_size()){
            while(OL->get_drink(j-1)->get_name()==OL->get_drink(j)->get_name()){
                num_drinks++;
                same_name.push_back(OL->get_drink(j));
                j++;
            }
        }
        cout<<"I have "<<num_drinks<<" drinks for "<<
                OL->get_drink(i)->get_name()<<"\n";
        while(num_drinks!=0)
        {    
            same_name[num_drinks-1]->confirmOrder();
            cout<<"\n";
            num_drinks--;
            i++;
        }
        cout<<"\n";
        same_name.clear();
    }
}

CoolBarista::~CoolBarista(){}
/*************************** CoolBarista End **********************************/

/**************************** NewbieBarista ***********************************/
NewbieBarista::NewbieBarista(){}

NewbieBarista::NewbieBarista(const NewbieBarista &barista){}
    
NewbieBarista& NewbieBarista::operator=(const NewbieBarista &barista){
    return *this;
}

void NewbieBarista::deliverDrinks(OrderList* OL)
{
    // Insertion Sort sorts every next element in order.

    // Loops through the whole vector
    for (unsigned int i = 1; i < OL->get_size(); i++)
    {
        int j = i;
        //cout<<first_drink->get_name()<<second_drink->get_name()<<"\n";
		
        // Compares vec[1] to vec[0] (respectively) depending on the desired order
        while (j > 0)
        {
            int first_size = OL->get_drink(j-1)->get_size();
            int second_size = OL->get_drink(j)->get_size();
            //cout << first_name << second_name << "\n";
            if (first_size > second_size)
            {
                OL->swap_drinks(j, (j-1), OL);
            }
            j--;
        }
    }
//    cout << OL->get_drink(0)->get_size() << OL->get_drink(1)->get_size() << 
//                OL->get_drink(2)->get_size() << OL->get_drink(3)->get_size() << 
//                OL->get_drink(4)->get_size() << "\n";
    cout<<"Newbie Barista: Order's up!\n";
    vector<Drink*> same_size;
    for (unsigned int i = 1; i < OL->get_size();)
    {
        int j=i;
        int num_drinks=1;
        same_size.push_back(OL->get_drink(i-1));
        if(j<OL->get_size()){
            while(OL->get_drink(j-1)->get_size()==OL->get_drink(j)->get_size()){
                num_drinks++;
                same_size.push_back(OL->get_drink(j));
                j++;
                if(j==OL->get_size()){
                        break;
                }
            }
        }
        cout<<"I have "<<num_drinks<<" drinks of size "<<
                OL->get_drink(i-1)->get_size()<<"\n";
        while(num_drinks!=0)
        {    
            same_size[num_drinks-1]->confirmOrder();
            cout<<"\n";
            num_drinks--;
            i++;
        }
        cout<<"\n";
        same_size.clear();
    }
}

NewbieBarista::~NewbieBarista(){}
/************************** NewbieBarista End *********************************/