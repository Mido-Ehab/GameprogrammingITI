//#include <iostream>
//using namespace std;
//
//class ComplexN {
//private:
//    double r1, r2, i1, i2;
//    static int OCounter;
//public:
//    ComplexN();
//    ComplexN(double real1 = 0, double imag1 = 0, double real2 = 0, double imag2 = 0);
//    ComplexN(double real, double imag);
//    ~ComplexN();
//
//    void setR1(double real1);
//    void setR2(double real2);
//    void setI1(double imag1);
//    void setI2(double imag2);
//
//    double getR1();
//    double getR2();
//    double getI1();
//    double getI2();
//
//    double real(double r1, double r2);
//    double img(double i1, double i2);
//
//    void comSum();
//    void comSub();
//    void Ans();
//
//    static int getInstanceCount();
//};
//
//int ComplexN::OCounter = 0;
//
//ComplexN::ComplexN()
//{
//    this->r1 = 0;
//    this->r2 = 0;
//    this->i1 = 0;
//    this->i2 = 0;
//    OCounter++;
//}
//
//
//ComplexN::ComplexN(double real1, double imag1, double real2, double imag2)
//{
//    this->r1 = real1;
//    this->r2 = real2;
//    this->i1 = imag1;
//    this->i2 = imag2;
//    OCounter++;
//}
//
//ComplexN::ComplexN(double real, double imag) {
//    real = this->r1 + this->r2;
//    imag = this->r1 - this->r2;
//
//    OCounter++;
//}
//
//ComplexN::~ComplexN() {
//
//    cout << "Instance Destroyed" << endl;;
//    OCounter--;
//}
//
//void ComplexN::setR1(double real1) {
//    this->r1 = real1;
//}
//
//void ComplexN::setR2(double real2) {
//    this->r2 = real2;
//}
//
//void ComplexN::setI1(double imag1) {
//    this->i1 = imag1;
//}
//
//void ComplexN::setI2(double imag2) {
//    this->i2 = imag2;
//}
//
//double ComplexN::getR1() {
//    return r1;
//}
//
//double ComplexN::getR2() {
//    return r2;
//}
//
//double ComplexN::getI1() {
//    return i1;
//}
//
//double ComplexN::getI2() {
//    return i2;
//}
//
//double ComplexN::real(double r1, double r2) {
//    return r1 + r2;
//}
//
//double ComplexN::img(double i1, double i2) {
//    return i1 + i2;
//}
//
//void ComplexN::Ans() {
//    cout << "Complex Number 1: " << r1 << " + " << i1 << "i" << endl;
//    cout << "Complex Number 2: " << r2 << " + " << i2 << "i" << endl;
//}
//
////struct ComResult {
////    double real;
////    double imag;
////};
//
//void ComplexN::comSum() {
//    double sumReal = r1 + r2;
//    double sumImag = i1 + i2;
//    cout << "Sum: " << sumReal << " + " << sumImag << "i" << endl;
//}
//
//void ComplexN::comSub() {
//    double subReal = r1 - r2;
//    double subImag = i1 - i2;
//    cout << "Difference: " << subReal << " + " << subImag << "i" << endl;
//}
//
//int ComplexN::getInstanceCount() {
//    return OCounter;
//}
//
//int main() {
//
//    int choice;
//    char con;
//
//
//    do {
//        cout << "choose the mode you want  1 for sum, 2 for sub : ";
//        cin >> choice;
//        switch (choice)
//        {
//        case 1:
//        {
//            ComplexN c(1.3, 2.5, 3.2, 4.6);
//            c.Ans();
//
//            c.comSum();
//
//
//            /* ComResult sum = comSum(1, 2, 3, 4);
//             ComResult sub = comSub(1, 2, 3, 4);
//
//             cout << "Sum: " << sum.real << " + " << sum.imag << "i" << endl;
//             cout << "Difference: " << sub.real << " + " << sub.imag << "i" << endl;*/
//            cout << "Current instance count: " << ComplexN::getInstanceCount() << endl;
//            break;
//
//        }
//
//        case 2:
//        {
//            ComplexN c(1.3, 2.5, 3.2, 4.6);
//            c.Ans();
//            c.comSub();
//            cout << "Current instance count: " << ComplexN::getInstanceCount() << endl;
//            break;
//        }
//        default:
//            break;
//        }
//        cout << "Current instance count after destroy: " << ComplexN::getInstanceCount() << endl;
//        cout << "press any key then enter to continue or press q ";
//        cin >> con;
//    } while (con != 'q');
//    return 0;
//}