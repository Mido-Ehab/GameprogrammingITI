#include <iostream>
using namespace std;
#pragma once
class ComplexNo
{
private:
    double r1, r2, i1, i2;
    static int OCounter; // Static variable for instance counter

public:
    ComplexNo();
    ComplexNo(double real1, double imag1); // Constructor for real1 and imag1
    ComplexNo(double real2, double imag2, bool dummy); // Constructor for real2 and imag2
    ComplexNo(float real, float imag); // Constructor for real and imag
    ~ComplexNo();
    void setR1(double real1);
    void setR2(double real2);
    void setI1(double imag1);
    void setI2(double imag2);
    double getR1();
    double getR2();
    double getI1();
    double getI2();
    double real(double r1, double r2);
    double img(double i1, double i2);
    void comSum(ComplexNo c2); // Updated method signature
    void comSub(ComplexNo c2); // Updated method signature
    void Ans();
    void Ans2(); // Method to display the second complex number
    static int getInstanceCount(); // Static method to get instance count
};