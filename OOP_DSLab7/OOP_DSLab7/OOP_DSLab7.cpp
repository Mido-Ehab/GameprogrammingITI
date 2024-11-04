#include <iostream>
using namespace std;


class geoShape 
{

public:


    virtual void area() {
        cout << "Calc. area of nothing !!" << endl;
    }
};

class Circle :public geoShape
{
    double r;
public:
 
   

    Circle(double r) 
    {
        this->r = r;
    }

    void area() override{
        double aC;
        aC = r * r * 3.14;
        cout << "the area of the circle : " << aC << endl;
    }
};


class Triangle :public geoShape
{
    double l;
    double h;
public:
    

    Triangle(double l, double h)
    {
        this->l = l;
        this->h = h;
    }

   
    void area() {
        double aT;
        aT= ( l*h)/2;
        cout << "the area of the triangle : " << aT << endl;
    }
};

class Rectangle :public geoShape
{
    double l;
    double h;
public:


    Rectangle(double l, double h)
    {
        this->l = l;
        this->h = h;
    }
    
    void area()  {
        int aR;
        aR = l * h;
        cout << "the area of the rectangle : " << aR << endl;
    }
};

class Square :public geoShape
{
    double l;
public:
    

    Square(double l) 
    {
        this->l = l;
    
    }

  
    void area() override  {
        int aS;
        aS = l * l;
        cout << "the area of the square : " << aS << endl;
    }
};


class Character 
{
public:
    virtual void Attack() {
        cout << "char is attacking " << endl;
    }
};

class player:public Character
{
public:
    void Attack() override{
        cout << "player is attacking " << endl;
    }
};

class NPC: public Character
    {
    public:
        void Attack() override {
            cout << "NPC is attacking " << endl;
        }
    }; 

class Boss :public NPC 
{
public:
    void Attack() override
    {
        cout << "Boss is attacking" << endl;
    }
};

void Attack(Character *character)
{
    character->Attack();
}

void area(geoShape* geo) {
    geo->area();

}


//class object{};
//
//class base : object 
//{
//public:
//    int publicInt;
//protected:
//    int protectedInt;
//private:
//    int privateInt;
//};
//
//class Child : private base {
//    void doSomething()
//    {
//        
//    }
//
//};
//
//class grandChild : Child {
//    void doSomething()
//    {
//       
//    }
//
//};
//
//class Cousin :Child,object
//{
//    
//};

int main()
{
    Square sq(5);
    Circle c(6);
    Triangle T(5,8);
    Rectangle re(5,9);

    area(&sq);
    area(&re);
    area(&c);
    area(&T);
    

    //Character characterOne;
    //player playerOne;
    //NPC Cop;
    //Boss b1;
    //Attack(&b1);//called the copy constructor

}
