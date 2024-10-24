#include <iostream>
#include <vector>
#include <string>
using namespace std;

void FiveMultiply(int* x, int x_)
{
    if (x_ == 0)  
    {
        return;
    }

    (*x) += 5;  

    cout << *x-1<<endl;
    FiveMultiply(x, x_ - 1);
}

int power(int base, int exp)
{
    if (exp == 0) 
    {
        return 1;
    }
    return base * power(base, exp - 1);
}


void factorial(int* number, int number_)
{
    if (number_ == *number)
    {
        (number_--);
    }
    *number *= number_;
    if (number_ > 1)
    {
        factorial(number, number_ - 1);
    }
}


struct InventoryItem
{
    string name;
    //int quantity;
    vector<string> items;

    void addItem(const string& newItem) 
    {
        items.push_back(newItem);
    }
};

int main()
{
    int choice;
    char cont;
    int number;
    InventoryItem p1,p2;

    int x = 1;
    int n ;


    do {
        cout << "menu" << endl;
        cout << "1. Calculate factorial" << endl;
        cout << "2. Manage inventory" << endl;
        cout << "3. Calculate power" << endl;
        cout << "4. five time table" << endl;
        cout << "Choose mode from 1 to 4 : ";
        cin >> choice;


        switch (choice)
        {
        case 1:
            cout << "please enter the no. you want to get the factorial for it : ";
            cin >> number;
            factorial(&number, number);
            cout << "Value is : " << number << "\n";
            break;
        case 2:

            p1.name = "potion";
            //p1.quantity = 5;
            p1.addItem(p1.name);
            p1.name = "knife";
            //p1.quantity = 3;
            p1.addItem(p1.name);


            p2.name = "Boomb";
            //p2.quantity = 4;
            p2.addItem(p2.name);
            p2.name = "potion";
            //p2.quantity = 2;
            p2.addItem(p2.name);

            cout << "Items in the inventory : " << endl;

            for (const auto& item : p1.items)
            {
                cout << "player 1 has: " << endl;
                cout << " - " << item << endl;
            }
            for (const auto& item : p2.items)
            {
                cout << "player 2 has : " << endl;
                cout << " - " << item << endl;
            }

            break;

        case 3:
            int base, exp;
            cout << "enter the base number""\n";
            cin >> base;
            cout << "enter the power""\n";
            cin >> exp;
            cout << base << " raised to the power of " << exp << " is " << power(base, exp) << endl;

            break;


        case 4:
           
            cout << " no. to represent the time tabl of five to : " << endl;
            cin >> n;

            FiveMultiply(&x, n);
            cout << "Final value is: " << x - 1 << "\n";
            cout << "press any key to continue or q to quit";
            cin >> choice;
            break;

        default:

            cout << "Invalid choice. Please select 1-4. Goodbye " << endl;
            return 0;
        }
        cout << "Press any key to continue or 'q' to quit: ";
        cin >> cont;
    } while (cont != 'q');

    }