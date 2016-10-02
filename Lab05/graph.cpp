/*
Sam Yager
graph.cpp

Implement a graph.
Consider what an empty graph is, you should be able to create this.
Limit number of connections between each pair to 1
*/


#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	string data;	//holds the data for this point
	Node* pointer;	//points to the next node in the list
	int num_connections;	//holds the number of connections this node has
	vector<string> array;	//holds all the connections this data point has to other data points
	Node(string word) {data=word; pointer=NULL; num_connections=0;};	//constructor
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
	curr -> num_connections++;
	return true;
}


int main () {
	LinkedListGraph Graph;
	Graph.Add("one");
	Graph.Add("two");
	Graph.Add("three");
	Graph.Add("four");
	Graph.Add("five");

	Graph.AddConnection("one","two");
	Graph.AddConnection("two","three");
	Graph.AddConnection("three","four");
	Graph.AddConnection("four","one");
	Graph.AddConnection("one", "four");
	Graph.AddConnection("four", "five");

	Graph.PrintGraph();
	return 0;
}


/*
Bipartite graph
can seperate into v1 which has no connections with itself 
and v2 which has not connections with itself
write:
bool IsBipartite()
that returns a true or false
Put in folder Lab05 for Monday
*/

