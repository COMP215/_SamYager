/*
Sam Yager
binary_tree.cpp
Implement a Binary Tree
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Node {
public:
	int data;		//holds number for each node in the tree
	Node *left;		//pointer to the left or any numbers greater than or equal to data
	Node *right;	//pointer to the left or any numbers less than data
	Node() {data = 0; left = right = NULL;}	//constructor
};

class Tree {
public:
	Node *head;				//pointer to the head of the Binary Tree
	Node *traverse;
	Tree() {head = NULL;};	//constructor
	void Add(int);			//adds a number to the tree in numerical order
	void PrintTree();		//calls PrintTree(Node)
	void PrintTree(Node *pointer);	//prints the data from the tree in numerical order
};

void Tree::Add(int num) {
/*
Adds a new node to the binary tree with num being the new data that is added
*/
	if (head == NULL) {
		head = new Node();
		head -> data = num;
	}
	else {
		Node *current;
		current = new Node();
		current -> data = num;

		Node *traverse;
		traverse = head;
		while (current -> data < traverse -> data && traverse -> left != NULL) {
			traverse = traverse -> left;
			while (current -> data >= traverse -> data && traverse -> right !=NULL) {
				traverse = traverse -> right;
			}
		}
		if (current -> data < traverse -> data) {
			traverse -> left = current;
		}
		else {
			traverse -> right = current;
		}
	}
}

void Tree::PrintTree() {
/*
Calls PrintTree to traverse through the tree
*/
	PrintTree(head);
}

void Tree::PrintTree(Node *pointer) {
/*
In order traversal of recursive nature to print the tree in numerical order
*/
	if (pointer -> left != NULL) 
		PrintTree(pointer -> left);
	cout << pointer -> data << endl;
	if (pointer -> right != NULL) 
		PrintTree(pointer -> right);
}

int main() {
	Tree tree;
	tree.Add(17);
	tree.Add(15);
	tree.Add(20);
	tree.Add(5);
	tree.Add(10);
	tree.Add(7);
	tree.Add(9);
	tree.Add(8);
	tree.Add(11);
	tree.PrintTree();
	return 0;
}

