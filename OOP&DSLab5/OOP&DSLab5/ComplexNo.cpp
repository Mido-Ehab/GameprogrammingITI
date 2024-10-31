#include "ComplexNo.h"
int ComplexNo::OCounter = 0;

ComplexNo::ComplexNo() {
    this->r1 = 0;
    this->r2 = 0;
    this->i1 = 0;
    this->i2 = 0;
    OCounter++;
    cout << "Instance Created, Current instance count: " << OCounter << endl;
}

ComplexNo::ComplexNo(double real1, double imag1) {
    this->r1 = real1;
    this->i1 = imag1;
    OCounter++;
    cout << "Instance Created, Current instance count: " << OCounter << endl;
}

ComplexNo::ComplexNo(double real2, double imag2, bool dummy) {
    this->r2 = real2;
    this->i2 = imag2;
    OCounter++;
    cout << "Instance Created, Current instance count: " << OCounter << endl;
}

//ComplexNo::ComplexNo(float real, float imag) {
//    this->r1 = real;
//    this->i1 = imag;
//    this->r2 = 0;
//    this->i2 = 0;
//    OCounter++; 
//    cout << "Instance Created"<<endl<< "Current instance count : " << OCounter << endl;
//}

ComplexNo::~ComplexNo() {
    cout << endl;
    cout << "Instance Destroyed" << endl;
    cout << "Current instance count: " << OCounter;
    OCounter--; // Decrement the instance counter
}

void ComplexNo::setR1(double real1) {
    this->r1 = real1;
}

void ComplexNo::setR2(double real2) {
    this->r2 = real2;
}

void ComplexNo::setI1(double imag1) {
    this->i1 = imag1;
}

void ComplexNo::setI2(double imag2) {
    this->i2 = imag2;
}

double ComplexNo::getR1() {
    return r1;
}

double ComplexNo::getR2() {
    return r2;
}

double ComplexNo::getI1() {
    return i1;
}

double ComplexNo::getI2() {
    return i2;
}

double ComplexNo::real(double r1, double r2) {
    return r1 + r2;
}

double ComplexNo::img(double i1, double i2) {
    return i1 + i2;
}

void ComplexNo::comSum(ComplexNo c2) {
    double sumReal = r1 + c2.getR2();
    double sumImag = i1 + c2.getI2();
    cout << "Sum: " << sumReal << " + " << sumImag << "i" << endl;
}

void ComplexNo::comSub(ComplexNo c2) {
    double subReal = r1 - c2.getR2();
    double subImag = i1 - c2.getI2();
    cout << "Difference: " << subReal << " + " << subImag << "i" << endl;
}

void ComplexNo::Ans() {
    cout << "Complex Number 1: " << r1 << " + " << i1 << "i" << endl;
}

void ComplexNo::Ans2() {
    cout << "Complex Number 2: " << r2 << " + " << i2 << "i" << endl;
}

int ComplexNo::getInstanceCount() {
    return OCounter;
}

int main() {
    int choice;
    char con;
    do {
        cout << "Choose the mode you want: 1 for sum, 2 for sub: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            {
                ComplexNo c1(1.3, 2.5); // Constructor for r1, i1
                ComplexNo c2(3.2, 4.6, true); // Constructor for r2, i2
                c1.Ans();
                c2.Ans2(); // Display the second complex number
                c1.comSum(c2); // Pass the second complex number
                /*   cout << "Current instance count: " << ComplexNo::getInstanceCount() << endl;*/
            }
            break;
        }
        case 2: {
            {
                ComplexNo c1(1.3, 2.5); // Constructor for r1, i1
                ComplexNo c2(3.2, 4.6, true); // Constructor for r2, i2
                c1.Ans();
                c2.Ans2(); // Display the second complex number
                c1.comSub(c2); // Pass the second complex number
                /*     cout << "Current instance count: " << ComplexNo::getInstanceCount() << endl;*/
            }
            break;
        }
        default:

            break;
        }
        cout << endl;
        cout << "Press any key then enter to continue or press q: ";
        cin >> con;
    } while (con != 'q');
    return 0;
}
