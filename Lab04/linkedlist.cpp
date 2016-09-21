/*
Sam Yager
LinkedList.cpp
Implement a class based linked list
*/

#include <iostream>
#include <iomanip>
using namespace std;
#include "LinkedList.hpp"

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

bool LinkedList::Search(string word) {
	Node *curr = head;
	while (curr!=NULL) {
		if (word == curr->data) {
			cout << word << " is in linked list" << endl;
			return true;
		} else {
			curr = curr -> pointer;
		}
	}
	cout << word << " is not in linked list" << endl;
	return false;
}

bool LinkedList::Delete(string word) {
	if (LinkedList::Search(word) == false) {
		cout << "Cannot delete " << word << " because it doest not exist in the linked list" << endl;
		return false;
	}
	else {
		Node *curr = head;
		Node *behind = head;
		while (curr->data != word) {
			behind = curr;
			curr = curr -> pointer;
		}
		behind -> pointer = curr -> pointer;
		cout << curr->data << " was deleted" << endl;
		delete curr;
		return false;
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

