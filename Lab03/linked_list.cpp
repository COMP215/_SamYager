/*
Sam Yager
linked_list.cpp
Implement a class based linked list
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Node {
public:
	string data;		//holds the data for each node
	Node *pointer;	//holds a pointer to point to the next node in the list
	Node() {data = ""; pointer = NULL;}
};

class LinkedList {
public:
	Node *head;
	Node *tail;
	LinkedList() {head = tail = NULL;};
	void AddToTail(string);
	void AddToHead(string);
	void PrintList();
};


void LinkedList::AddToTail(string word) {
//Adds a new node to the tail of the linked list with word as the new added data

	if (head == NULL) {
		head = new Node();
		head -> data = word;
		tail = head;
	}
	else {
		Node *current;
		current = new Node();
		current -> data = word;
		tail -> pointer = current;
		tail = current;
	}
}

void LinkedList::AddToHead(string word) {
//Adds a new node to the head of the linked list with word as the new added data

	if (head == NULL) {
		head = new Node();
		head -> data = word;
		tail = head;
	}
	else {
		Node *current;
		current = new Node();
		current -> data = word;
		current -> pointer = head;
		head = current;
	}
}

void LinkedList::PrintList() {
//Traverses throught the linked list and prints data in order
	Node *traverse = head;
	while (traverse!=NULL) {
		cout << traverse -> data << endl;
		traverse = traverse -> pointer;
	}
}

int main() {
	LinkedList List;

	List.AddToTail("5");
	List.AddToTail("7");
	List.AddToHead("3");
	List.PrintList();
	return 0;
}

