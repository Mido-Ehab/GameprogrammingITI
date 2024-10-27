#include <iostream>
#include <vector>
#include <string>
using namespace std;

//employee data

struct Employee {
	int ID;
	string name;
	double salary;
	Employee(){}
	Employee(int id, string name, double salary) 
	{
		 this-> ID = id;
		 this->name = name;
		 this->salary = salary;
	}
};

// Node Build For the linked list

struct Node {
	Employee data;
	Node* prev;
	Node* next;

	Node(Employee data) {
		this->data = data;
		this->prev = nullptr;
		this->next = nullptr;
	}
};


class EmployeeList {
	Node* head;
	Node* tail;

public:
	EmployeeList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void addEmployee(int id, string name, double salary) {
		Employee emp(id, name, salary);
		Node* new_node = new Node(emp);

		if (!head)
		{
			head = tail = new_node;
		}
		else {
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;

		}
	}

	void deleteEmployee(int id) {
		Node* current = head;
		while (current) {                       
			if (current->data.ID == id) {        
				if (current->prev) {             
					current->prev->next = current->next; 
				}
				else {
					head = current->next;
				}
				if (current->next) {             
					current->next->prev = current->prev; 
				}
				else {
					tail = current->prev;      
				}
				delete current;                 
				cout << "Employee with ID " << id << " deleted.\n";
				return;
			}
			current = current->next;            
		}
		cout << "Employee with ID " << id << " not found.\n";
	}

	Node* findEmployee(int id) {
		Node* current = head;
		while (current) {
			if (current->data.ID == id) {
				return current;
				current = current->next;
			}
			return nullptr;
		}
	}

	void replaceEmployee(int id, string newname,double newsalary) 
	{
		Node* node = findEmployee(id);
		if (node) {
			node->data.name = newname;
			node->data.salary = newsalary;
			cout<<"Employee with ID : "<<id<<"replaced with another" <<endl;
		}
		else
		{
			cout << "Id : " << id << "not found" << endl;
		}
	}

	void display() {
		Node* current = head;
		while (current) {
			cout << "ID : " << current->data.ID << ", Name: " << current->data.name << ", Salary: "
				<< current->data.salary << endl;
			current = current->next;

		}
	}

	~EmployeeList() {
		Node* current = head;
		while (current) {
			Node* nextNode = current->next;
			delete current;                      
			current = nextNode;                  
		}
	}
};

	


int main()
{
	EmployeeList list;

	list.addEmployee(1, "mohamed", 50000);
	list.addEmployee(57, "khaled", 7000);
	list.addEmployee(88, "hussin", 8800);
	cout << "All Employee : " << endl;
	list.display();
	list.deleteEmployee(57);
	list.display();
	Node* found = list.findEmployee(1);
	if (found)
		cout << "Found Employee with ID 2: " << found->data.name << "\n";
	list.replaceEmployee(1, "kassem", 9000);
	cout << "after : ";
	list.display();

}


