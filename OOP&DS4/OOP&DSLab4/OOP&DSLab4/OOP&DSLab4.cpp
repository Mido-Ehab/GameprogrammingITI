//-----------Binary Tree & queue Task ---------------------------------------------
//---------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

//------Tree-----------------------------
//---------------------------------------

struct Student {
	int id;
	string name;
	int grade;
	Student* left = nullptr;
	Student* right = nullptr;
};

struct StudentTree {
	Student* root = nullptr;

	void insertStudent(int id, string name, int grade) {
		Student* newStudent = new Student{ id, name, grade };
		if (root == nullptr) {
			root = newStudent;
		}
		else {
			Student* current = root;
			Student* parent = nullptr;
			while (current != nullptr) {
				parent = current;
				if (id < current->id) { //          ro7 3la elshemal lw el id 2a2al mn el leaf el e7na feha 
					current = current->left;
				}
				else {                  //          ro7 3la elymeen lw el id 2a2al mn el leaf el e7na feha 
					current = current->right;
				}
			}
			if (id < parent->id) {
				parent->left = newStudent;
			}
			else {
				parent->right = newStudent;
			}
		}
	}

	Student* findStudentByID(int id) {
		Student* current = root;
		while (current != nullptr) {
			if (current->id == id) {
				return current;
			}

			///nfs klam el fo2 bs hena ba search 

			else if (id < current->id) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
		return nullptr;
	}

	Student* getSuccessor(Student* curr)
	{
		curr = curr->right;
		while (curr != NULL && curr->left != NULL)
			curr = curr->left;
		return curr;
	}

	Student* delNode(Student* root, int x)
	{
		if (root == nullptr) {
			cout << "Tree is empty or not in the tree" << endl;
			return root;
		}

		if (root->id > x)
		{
			root->left = delNode(root->left, x);
		}
		else if (root->id < x)
		{
			root->right = delNode(root->right, x);
		}
		else
		{
			// Cases when root has 0 children
		  // or only right child
			if (root->left == NULL) {
				Student* temp = root->right;
				delete root;
				return temp;
			}

			// When root has only left child
			if (root->right == NULL)
			{
				Student* temp = root->left;
				delete root;
				return temp;
			}
			Student* succ = getSuccessor(root);
			root->id = succ->id;
			root->right = delNode(root->right, succ->id);
		}
		return root;
	}

	void displayInOrder(Student* root) {
		if (root != nullptr) {
			displayInOrder(root->left);
			cout << "Student: " << root->name << ", Grade: " << root->grade << endl;
			displayInOrder(root->right);
		}
	}
};


//-------------------------------------------------------------
//-------------Queue Task----------------------
//----------------------------------------------


struct Studentq {
	string name;
	int Grade;
	Studentq* next = nullptr;
};

struct queue {
	Studentq* first = nullptr;
	Studentq* last = nullptr;

	void enqueue(Studentq* newStud) {
		if ((first == nullptr) && (last == nullptr)) {
			last = newStud;
			first = newStud;
		}
		last->next = newStud;
		last = newStud;
	}
	Studentq* dequeue() {
		if (first == nullptr) {
			cout << "dequeue is null" << endl;
			return nullptr;
		}
		Studentq* temp = first;
		first = temp->next;
	}

	Studentq* Search(int index) {
		if (first == nullptr) {
			cout << "Nothing here" << endl;
			return nullptr;
		}
		Studentq* current = first;
		int count = 0;
		while (current != nullptr && count < index) {
			current = current->next;
			count++;
		}
		if (current == nullptr) {
			cout << "Index out of range" << endl;
			return nullptr;
		}
		return current;
	}

	void enqueueAt(Studentq* newStud, int index) {
		if (index == 0) {
			newStud->next = first;
			first = newStud;
			if (last == nullptr) {
				last = newStud;
			}
			return;
		}
		Studentq* prev = Search(index - 1);
		if (prev == nullptr) {
			cout << "Index out of range, cannot insert" << endl;
			return;
		}
		newStud->next = prev->next;
		prev->next = newStud;
		if (newStud->next == nullptr) {
			last = newStud;
		}

	}

};

int main() {
	char con = NULL;
	int choice;
	StudentTree tree;
	queue q;
	do {
		cout << "1. Tree operations\n";
		cout << "2. Queue operations\n";
		cout << "Enter your choice: ";
		cin >> choice;


		switch (choice) {
		case 1: {
			tree.insertStudent(1, "Mohamed", 90);
			tree.insertStudent(3, "Karim", 85);
			tree.insertStudent(2, "Abdo", 88);
			tree.insertStudent(5, "Salma", 95);
			tree.insertStudent(4, "abeer", 80);

			int id;
			cout << "Search student by ID: ";
			cin >> id;
			Student* student = tree.findStudentByID(id);
			if (student != nullptr) {
				cout << "Found student: " << student->name << " with grade " << student->grade << endl;
			}
			else {
				cout << "Student with ID " << id << " not found." << endl;
			}


			cout << "Enter the student ID to delete: ";
			cin >> id;
			tree.root = tree.delNode(tree.root, id);


			cout << "Remaining students in the tree :" << endl;
			tree.displayInOrder(tree.root);
			break;
		}
		case 2: {
			// queue code
			Studentq s1 = { "Mohamed", 100 };
			Studentq s2 = { "Karim",60 };
			Studentq s3 = { "abdo",50 };

			q.enqueue(&s1);
			q.enqueue(&s2);
			q.enqueue(&s3);

			Studentq* Search = q.Search(2);
			if (Search != nullptr) {
				cout << "Peeking at index " << 2 << ": " << Search->name << " with grade " << Search->Grade << endl;
			}

			cout << "Before :" << endl;
			Studentq* curr = q.first;
			while (curr != nullptr) {
				cout << "Student: " << curr->name << ", Grade: " << curr->Grade << endl;
				curr = curr->next;
			}

			// hkhly eluser el yktb meen el student we y7oto fe any index bs msh radya !!!??
			int index;
			string name;
			int grade;
			cout << "Enter the index for the new student ";
			cin >> index;
			cout << "new student name: ";
			cin >> name;
			cout << "grade : ";
			cin >> grade;

			Studentq* newStudent = new Studentq{ name, grade };
			q.enqueueAt(newStudent, index);

			cout << endl;
			cout << "After Updating  " << index << ":" << endl;
			curr = q.first;
			while (curr != nullptr) {
				cout << "Student: " << curr->name << ", Grade: " << curr->Grade << endl;
				curr = curr->next;
			}
		}
		}
		cout << "Press any key then enter to continue or q to quit : ";
		cin >> con;
	} while (con != 'q');
	return 0;
}


//#include <iostream>
//#include<string>
//using namespace std;
//
//struct Node {
//	string name;
//	string address;
//	Node *next = nullptr;
//};
//
//struct stack {
//	Node* top = nullptr;
//	void push(Node* newNode)
//	{
//		if (top == nullptr)
//		{
//			top = newNode;
//			return;
//		}
//		newNode->next = top;
//		top = newNode;
//		
//	}
//
//
//	Node* pop()
//	{
//		if (top == nullptr)
//		{
//			cout << "stack is empty";
//			return NULL;
//		}
//		Node* temp;
//		temp = top;
//		top = top->next;
//		return temp;
//	}
//
//
//	int peek() {
//
//	}
//
//
//	void display() {
//
//
//	}
//
//};
//
//
//int main()
//{
//  {
//	Node n1;
//	Node n2;
//	Node n3;
//
//	n1.name = "mohamed";
//	n2.name = "Ehab";
//	n3.name = "Third";
//
//	stack s;
//
//	s.push(&n1);
//	s.push(&n2);
//	s.push(&n3);
//
//	for (int i = 0; i < sizeof(s);i++) {
//		Node* temp = s.pop();
//		if (temp !=NULL)
//		cout << "name: " <<(*temp).name << endl;
//	}
//   }
//}

//

//-------------Stack With Linked List my edition------------
//#include<iostream>
//using namespace std;
//
//struct node {
//	int data;
//	node* next;
//};
//
//node* top = NULL;
//void display();
//void push(int value);
//int pop();
//int peek();
//
//int main() {
//	push(5);
//	push(10);
//	push(20);
//	display();
//	cout << "-------------------" << endl;
//	pop();
//	display();
//	cout << "-------------------" << endl;
//	peek();
//}
//
//void push(int value) {
//	node* new_node = new node;
//	new_node->data = value;
//	new_node->next = top;
//	top = new_node;
//}
//
//int pop() {
//	int value;
//	if (top == NULL) {
//		cout << "stack is empty";
//	}
//	else {
//		node* first_node = top;
//		top = first_node->next;
//		value = first_node->data;
//		delete(first_node);
//		return value;
//	}
//
//
//}
//int peek() {
//	if (top == NULL) {
//		cout << "stack is empty";
//	}
//	else {
//		return top->data;
//	}
//}
//void display() {
//	node* current;
//	if (top == NULL) {
//		cout << "stack is empty" << endl;
//	}
//	else {
//		current = top;
//		while (current != NULL) {
//			cout << current->data << "\n";
//			current = current->next;
//		}
//	}
//}
// 
// 


	//int main()
	//{
	//	queue q;
	//	Studentq s1 = { "Mohamed", 100 };
	//	Studentq s2 = { "Karim",60 };
	//	Studentq s3 = { "abdo",50 };

	//	q.enqueue(&s1);
	//	q.enqueue(&s2);
	//	q.enqueue(&s3);

	//	Studentq* Search = q.Search(2);
	//	if (Search != nullptr) {
	//		cout << "Peeking at index " << 2 << ": " << Search->name << " with grade " << Search->Grade << endl;
	//	}
	//	
	//	cout << "Before :" << endl;
	//	Studentq* curr = q.first;
	//	while (curr != nullptr) {
	//		cout << "Student: " << curr->name << ", Grade: " << curr->Grade << endl;
	//		curr = curr->next;
	//	}

	//	// hkhly eluser el yktb meen el student we y7oto fe any index bs msh radya !!!??
	//	int index;
	//	string name;
	//	int grade;
	//	cout << "Enter the index for the new student ";
	//	cin >> index;
	//	cout << "new student name: ";
	//	cin >> name;
	//	cout << "grade : ";
	//	cin >> grade;

	//	Studentq* newStudent = new Studentq{ name, grade };
	//	q.enqueueAt(newStudent, index);

	//	cout << endl;
	//	cout << "After Updating  " << index << ":" << endl;
	//	curr = q.first;
	//	while (curr != nullptr) {
	//		cout << "Student: " << curr->name << ", Grade: " << curr->Grade << endl;
	//		curr = curr->next;
	//	}

	//}

