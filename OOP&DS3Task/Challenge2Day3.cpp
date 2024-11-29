#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Employee data
struct Employee {
	int ID;
	string name;
	double salary;
	Employee() {}
	Employee(int id, string name, double salary) {
		this->ID = id;
		this->name = name;
		this->salary = salary;
	}
};

// Node for the linked list
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

		if (!head) {
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
			}
			current = current->next;
		}
		return nullptr;
	}

	void replaceEmployee(int id, string newname, double newsalary) {
		Node* node = findEmployee(id);
		if (node) {
			node->data.name = newname;
			node->data.salary = newsalary;
			cout << "Employee with ID " << id << " replaced.\n";
		}
		else {
			cout << "Employee with ID " << id << " not found.\n";
		}
	}

	void display() {
		Node* current = head;
		while (current) {
			cout << "ID: " << current->data.ID << ", Name: " << current->data.name << ", Salary: "
				<< current->data.salary << endl;
			current = current->next;
		}
	}

	
	Node* getMiddle(Node* head) {
		if (!head) return head;
		Node* slow = head;
		Node* fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	Node* sortedMerge(Node* left, Node* right) {
		if (!left) return right;
		if (!right) return left;

		if (left->data.ID <= right->data.ID) {
			left->next = sortedMerge(left->next, right);
			left->next->prev = left;
			left->prev = nullptr;
			return left;
		}
		else {
			right->next = sortedMerge(left, right->next);
			right->next->prev = right;
			right->prev = nullptr;
			return right;
		}
	}

	Node* mergeSort(Node* node) {
		if (!node || !node->next) return node;

		Node* middle = getMiddle(node);
		Node* nextToMiddle = middle->next;
		middle->next = nullptr;

		Node* left = mergeSort(node);
		Node* right = mergeSort(nextToMiddle);

		return sortedMerge(left, right);
	}

	void sortEmployeesByID() {
		head = mergeSort(head);
		Node* temp = head;
		while (temp && temp->next) temp = temp->next;
		tail = temp;
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

int main() {
	EmployeeList list;

	list.addEmployee(1, "Mohamed", 50000);
	list.addEmployee(88, "Khaled", 7000);
	list.addEmployee(57, "Hussin", 8800);


	//-----display--------
	cout << "All Employees:\n";
	list.display();
	cout << endl;
	//------mergeSort------
	cout << "\nSorting employees by ID:\n";
	list.sortEmployeesByID();
	list.display();
	cout << endl;
	//------delete---------
	list.deleteEmployee(88);
	list.display();
	cout << endl;
	//------replace--------
	list.replaceEmployee(57, "Kassem", 10000);
	list.display();
	cout << endl;
	//------add------------
	list.addEmployee(99, "Ronaldo", 900000);
	list.display();
	cout << endl;
	//-------find---------
	Node* found = list.findEmployee(99);
	if (found)
		cout << "Found Employee with ID 2: " << found->data.name << "\n";
}
