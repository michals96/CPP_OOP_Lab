#ifndef MAIN_H
#define MAIN_H
#include <iostream>

class ObiektMiotajacy{
    public:
    int value=0;
    virtual void PrzedstawSie(){} 
    void Rzuc();
    virtual int getVal()const{return value;}
    virtual ~ObiektMiotajacy(){}
    
};
class typ1:public ObiektMiotajacy{
    public:
    int value=1;
    void PrzedstawSie(){
        std::cout << "Nazywam sie "<<value<<" (adres obiektu:<"<<this<<">)"<<std::endl;
    }
    int getVal()const{return value;}
    virtual ~typ1(){}
};
class typ2:public ObiektMiotajacy{
    public:
    int value=2;
    void PrzedstawSie(){
        std::cout << "Nazywam sie "<<value<<" (adres obiektu:<"<<this<<">)"<<std::endl;
    }
    int getVal()const{return value;}
    virtual ~typ2(){}
};
class typ3:public ObiektMiotajacy{
    public:
    int value=3;
    void PrzedstawSie(){
        std::cout << "Nazywam sie "<<value<<" (adres obiektu:<"<<this<<">)"<<std::endl;
    }
    int getVal()const{return value;}
    virtual ~typ3(){}
};
class typ4:public ObiektMiotajacy{
    public:
    int value=4;
    void PrzedstawSie(){
        std::cout << "Nazywam sie "<<value<<" (adres obiektu:<"<<this<<">)"<<std::endl;
    }
    int getVal()const{return value;}
    virtual ~typ4(){}
};
void Przetworz(ObiektMiotajacy *obj);
#endif