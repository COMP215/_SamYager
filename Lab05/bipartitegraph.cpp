/*
Bipartite graph
Can seperate into v1 which has no connections with itself 
and v2 which has not connections with itself
write:
bool IsBipartite()
that returns a true or false
Put in folder Lab05 for Monday
*/


#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	string data;	//holds the data for this point
	Node* pointer;	//points to the next node in the list
	vector<string> array;	//holds all the connections this data point has to other data points
	Node(string word) {data=word; pointer=NULL;};	//constructor
};

class LinkedListGraph {
	Node* head_;
	Node* tail_;
public:
	LinkedListGraph() {head_ = NULL; tail_ = NULL;};	//constructor
	bool Add(string);	//adds a new point to the graph
	bool Search(string);	//searches linked list for a given word
	void PrintGraph(); //prints all vectors in graph
	bool AddConnection(string, string); //adds a one way connection to the graph
	bool IsBipartite(); //finds if the graph is bipartite
};

bool LinkedListGraph::Add(string word) {
	if (head_ == NULL) {
		//if the linked list is empty, add a first node
		head_ = new Node(word);
		tail_ = head_;
		return true;
	} else {
		//adds a new node to the tail of the linked list
		Node *current;
		current = new Node(word);
		tail_ -> pointer = current;
		tail_ = current;
		return true;
	}
}

bool LinkedListGraph::Search(string word) {
	Node *curr = head_;
	while (curr!=NULL) {
		if (word == curr->data) 
			//returns true if it finds the word
			return true;
		else 
			curr = curr -> pointer;
	}
	//returns false if word is not in liked list
	return false;
}


void LinkedListGraph::PrintGraph() {
	Node *traverse = head_;
	while (traverse != NULL) {
		//traverses the list and prints out all the vectors in the graph
		cout << traverse -> data << " --> ";
		for (int i = 0; i < traverse -> array.size(); ++i)
			cout << traverse -> array[i] << ' ';
		cout << endl;
		traverse = traverse -> pointer;
	}
}

bool LinkedListGraph::AddConnection(string beginning, string end) {
	//first checks that both connections points are in the graph
	if (LinkedListGraph::Search(beginning)==false) {
		cout << beginning << " is not in the graph. Conection not added.\n";
		return false;
	}
	if (LinkedListGraph::Search(end)==false) {
		cout << end << " is not in the graph. Connection not added.\n";
		return false;
	}

	Node *curr = head_;
	while (curr -> data != beginning) {
		//finds the node that holds the beginning of the connection
		curr = curr -> pointer;
	}
	//adds the end connection to the array of the beginning connection
	curr -> array.push_back(end);

	return true;
}


bool LinkedListGraph::IsBipartite() {
	vector<string> v1;		//holds first set of vertices
	vector<string> notv1;	//holds vectors that cannot go in v1 because there is already a connection
	vector<string> v2;		//holds second set of vertices
	vector<string> notv2;	//holds vectors that cannot go in v2 because there is already a connection
	Node *current = head_;	//a pointer to keep track of what node we are looking at

	while (current != NULL) {
		if (v1.empty()) {	
		//if v1 is empty, add first vector to v1
			v1.push_back(current -> data);
			for (int i=0; i< current -> array.size(); ++i) {
				notv1.push_back(current -> array[i]);
			}
			current = current -> pointer;
		} else {
		//if v1 is not empty, check where the vector should go
			if (find(notv1.begin(), notv1.end(), current->data) == notv1.end()) {
			//vector can go in v1, so add it to v1
				v1.push_back(current -> data);
				for (int i=0; i< current -> array.size(); ++i) {
					notv1.push_back(current -> array[i]);
				}
				current = current -> pointer;
			} else {
			//vector cannot go in v1, so search v2
				if (v2.empty()) {
				//if v2 is empty, add first vector to v2
					v2.push_back(current -> data);
					for (int i=0; i< current -> array.size(); ++i) 
						notv2.push_back(current -> array[i]);
					current = current -> pointer;
				} else if (find(notv2.begin(), notv2.end(), current->data) == notv2.end()) {
				//vector can go in v2, so add it to v2
					v2.push_back(current -> data);
					for (int i=0; i< current -> array.size(); ++i) 
						notv2.push_back(current -> array[i]);
					current = current -> pointer;
				} else {
				//cannot go in vector 1 or 2 so return false
					cout << "Graph is not bipartite.\n";
					return false;
				}
			}
		}
	}
	cout << "Graph is bipartite.\n";
	return true;
}


int main () {
	LinkedListGraph Graph;
	Graph.Add("one");
	Graph.Add("two");
	Graph.Add("three");
	Graph.Add("four");
	Graph.Add("five");
	Graph.Add("six");

	Graph.AddConnection("one","two");
	Graph.AddConnection("two","three");
	Graph.AddConnection("three","four");
	Graph.AddConnection("four", "five");
	Graph.AddConnection("five","six");
	Graph.AddConnection("six","one");

	Graph.PrintGraph();
	Graph.IsBipartite();

	return 0;
}
