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




int main(){
	int h;
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
