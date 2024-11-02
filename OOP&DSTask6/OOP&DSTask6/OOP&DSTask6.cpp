#include <iostream>
#include <vector>
#include <string>
using namespace std;

//aggregation

class screen {/*....*/ };
class controller
{ 
public:
	void Event() {
		cout << "button pressed" << endl;
	}
};


//---------------------M7war elkon------------------------------//
class Console
{
private:
	
protected:
	int x = 0;
	controller joystick;
public:
	void startButton()
	{
		/*++x;*/
		string s = "Welcome to PS";
		cout << s<<endl;
		
	}
	void newuser() {

	/*	++x;*/
		cout << "new user connected" << endl;
	}

	void controllerConected() 
	{
		joystick.Event();
	}


};



//composition
class gameConsoleType {

};

class person {
	string name;
	int age;


public:
	//association
	Console* playstation;

	void playAGame() {
		playstation->newuser();
	}

	void displayDetails() {
		name = "Mohamed";
		age = 24;
		cout << "Name : " << name << " Age : " << age<<endl;
	}
};

//inheritance
class serverClient :public Console 
{
public:
	void connected()
	{
		string pl = " user 1 connected";
		cout << pl << endl;
	}
	void incSteps()
	{
	
		cout << "this is step no.  : " << ++x << " User is playing" << endl;
	}
};

//--------------Complex Bonus-----------------------------------

class ComplexN
{
	double real1, img1;
public:
	ComplexN() {}
	ComplexN(double r1, double i1)
	{
		this->real1 = r1;
		/*	this->real2 = r2;*/
		this->img1 = i1;
		/*this->img2 = i2;*/
	}

	explicit operator float() {
		return real1 + img1;


	}

	ComplexN operator+ (ComplexN& right) {
		ComplexN result;

		result.real1 = real1 + right.real1;

		result.img1 = img1 + right.img1;



		cout << "Sum is = " << result.real1 << " + " << result.img1 << "i" << endl;

		return result;

	}

	ComplexN operator- (ComplexN& right) {
		ComplexN result;

		result.real1 = real1 - right.real1;

		result.img1 = img1 - right.img1;


		cout << "Sub is = " << result.real1 << " + " << result.img1 << "i" << endl;

		return result;

	}

	ComplexN operator != (ComplexN& right) {
		ComplexN result;

		result.real1 = real1 != right.real1;

		result.img1 = img1 != right.img1;


		cout << "!= is = " << result.real1 << " != " << result.img1 << "i";
		cout << " != " << "go away" << endl;

		return result;

	}

	ComplexN operator == (ComplexN& right) {
		ComplexN result;

		result.real1 = real1 == right.real1;

		result.img1 = img1 == right.img1;


		cout << "== is " << result.real1 << " == " << result.img1 << "i";
		cout << " == " << "Mlksh feah homa equal esh3rafak enta";

		return result;

	}

	void operator = (const ComplexN& right) {


		real1 = right.real1;

		img1 = right.img1;


		//if(result.real1 == result.img1)
		//{
		//
		//	cout << "= is " << result.real1 << " = " << result.img1 << "i";
		//
		//	cout << " = " << "Gd3 equal" << endl;
		//}
		//else
		//{
		//	cout << "ekhs 3lyk msh equal" << endl;
		//}
	}

	//---------------------------prefix

	ComplexN& operator++ () {

		real1 = real1 + 1;

		img1 = img1 + 1;




		cout << "++ = " << real1 << " + " << img1 << "i" << endl;

		return *this;

	}

	ComplexN& operator-- () {

		real1 = real1 - 1;

		img1 = img1 - 1;


		return *this;

	}

	ComplexN& operator++ (int) {



		ComplexN result = *this;

		++real1;
		++img1;

		return result;


	}

	ComplexN& operator-- (int) {



		ComplexN result = *this;

		--real1;
		--img1;

		return result;

	}

};




int main(){
	int h;


	ComplexN operation;

	ComplexN temp1 = ComplexN(1, 2);
	ComplexN temp2 = ComplexN(2, 3);
	do
	{
		cout << "Press 1 to enter Relation Between Objects or 2 for post&prefix or 0 to quit : " << endl;
		cin >> h;
		switch (h) {
		case 1:
		{
			serverClient p;
			Console c;
			person pe;
			c.startButton();
			p.connected();
			p.incSteps();

			pe.displayDetails();
			pe.playAGame();

			c.controllerConected();
			break;
		}

		case 2:
			



			operation = (temp1 + temp2);
			cout << endl;
			operation = temp1 - temp2;
			cout << endl;
			operation = temp1 != temp2;
			cout << endl;
			operation = temp1 == temp2;
			cout << endl;

			cout << (float)temp1 << endl;
			
			temp1++;
			cout << (float)temp1 << endl;

			--temp1;
			cout << (float)temp1 << endl;


			break;


		default:
			break;
		}
	} while (h!=0);

	


//
//
//class creature {
//
//protected:
//	void Breath() {}
//	int x;
//};
//
//class  Doctor : public creature
//{
//
//	void examine(person* patient){}
//	
//};
//
//class organ{};
//class Medicines {};
//class Cloth {};
//
//
//class person: public creature 
//{
//public:
//	void ay7aga() {
//		x=5;
//	}
//	//association
//	Doctor* doctor;
//	//----------
//	vector<organ> organs;
//	vector<Medicines> medicines;
//	vector<Cloth> clothes;
//};
//
//
//int main()
//{
//
//	person p;
//	p.ay7aga();
//}

 }
