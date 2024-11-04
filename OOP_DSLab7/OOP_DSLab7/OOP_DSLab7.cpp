#include <iostream>
#include <vector>
using namespace std;





class geoShape 
{

public:


    virtual double area() {
        cout << "Calc. area of nothing !!" << endl;
        return 0;
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

    double area() override{
        double aC;
        aC = r * r * 3.14;
        return aC;
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

   
    double area() {
        double aT;
        aT= ( l*h)/2;
        return aT;
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
    
    double area()  {
        double aR;
        aR = l * h;
        return aR;
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

  
    double area() override  {
        int aS;
        aS = l * l;
        return aS;
    }
};


double area(geoShape* geo) {
   
    return geo->area();
}


//vector of pointer type geoshape to access the area function that uses the pointer of the same type

double avgArea (vector <geoShape*> shapes)
{
    double avSum=0;
    int Length=0;

    for (geoShape* g : shapes)
    {
    
        avSum += area(g);
      /*  Length++;*/
    }

    return (avSum / shapes.size());
   
}


int main()
{
    Circle c(5);
    Triangle t(6, 5);
    Rectangle r(9, 5);
    Square s(8);

    vector <geoShape*> shapes;

    shapes.push_back(&c);
    shapes.push_back(&t);
    shapes.push_back(&r);
    shapes.push_back(&s);

    avgArea(shapes);

    cout << "Avg = " << avgArea(shapes);


    /*Square sq(5);
    Circle c(6);
    Triangle T(5,8);
    Rectangle re(5,9);

    area(&sq);
    area(&re);
    area(&c);
    area(&T);*/
    

    //Character characterOne;
    //player playerOne;
    //NPC Cop;
    //Boss b1;
    //Attack(&b1);//called the copy constructor

}


//class Creature 
//{
//public:
//    int ExistanceSince;
//    void DoCreatureThings()
//    {
//        cout << " do creature things "<<endl;
//    }
//};
//
////
//class FlyingBirds:virtual public Creature
//{
//public:
//    float wingLength;
//};
//
//class WalkingBirds : virtual public Creature
//{
//public:
//    float walkSpeed;
//
//};
//
//class Duck :public WalkingBirds, public FlyingBirds
//{
//   void DoCreatureThings() 
//    {
//
//    }
//};
//
//class Employee
//{
//public:
//    void doWork() {
//
//    }
//};
//
//class Manager : Employee
//{
//    vector <Employee> employees;
//    void InstructEmployees() 
//    {
//
//        for (Employee emp : employees)
//        {
//            emp.doWork();
//        }
//    }
//};
//
//
//class Character 
//{
//public:
//    virtual void Attack() {
//        cout << "char is attacking " << endl;
//    }
//};
//
//class player:public Character
//{
//public:
//    void Attack() override{
//        cout << "player is attacking " << endl;
//    }
//};
//
//class NPC: public Character
//    {
//    public:
//        void Attack() override {
//            cout << "NPC is attacking " << endl;
//        }
//    }; 
//
//class Boss :public NPC 
//{
//public:
//    void Attack() override
//    {
//        cout << "Boss is attacking" << endl;
//    }
//};
//
//void Attack(Character *character)
//{
//    character->Attack();
//}
//void DoCreatureThing(Creature& creature)
//{
//    creature.DoCreatureThings();
//}
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
