/*
Sam Yager
linkedlist.hpp
*/


#ifndef LinkedList_hpp
#define LinkedList_hpp

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
	bool Search(string);
	void PrintList();
	bool Delete(string);
};

#endif