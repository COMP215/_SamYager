/*
Sam Yager
dijkstra.cpp
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#include "dijkstra.hpp"

bool LinkedListGraph::AddVertex(string word) {
	if (head_ == NULL) {
		//if the linked list is empty, add a first node
		head_ = new Node(word);
		tail_ = head_;
		vertexcount++;
		return true;
	} else {
		//adds a new node to the tail of the linked list
		Node *current;
		current = new Node(word);
		tail_ -> pointer = current;
		tail_ = current;
		vertexcount++;
		return true;
	}
}

bool LinkedListGraph::Search(string word) {
	Node *curr = head_;
	while (curr!=NULL) {
		if (word == curr->vertex
	) 
			//returns true if it finds the word
			return true;
		else 
			curr = curr->pointer;
	}
	//returns false if word is not in liked list
	return false;
}

void LinkedListGraph::PrintGraph() {
	//prints the initial graph
	cout << "graph G {\n";
	cout << "node [shape = square];\n";
	cout << "node [color = blue];\n";
	Node *traverse = head_;
	while (traverse != NULL) {
		//traverses the list and prints out all the vectors in the graph
		for (int i = 0; i < traverse -> edge.size(); ++i) {
			cout << traverse -> vertex << " -- " << traverse -> edge[i] << "[ label = ";
			cout << traverse -> weight[i] << " ];" << endl;
		}
		traverse = traverse -> pointer;
	}
	cout << "}" << endl << endl;
}

void LinkedListGraph::PrintDijkstra() {
	//prints the graph with costs and weights
	cout << "graph G {\n";
	cout << "node [shape = square];\n";
	cout << "node [color = blue];\n";
	Node *traverse = head_;
	while (traverse != NULL) {
		//traverses the list and prints out all the vectors in the graph
		for (int i = 0; i < traverse -> edge.size(); ++i) {
			cout << traverse -> vertex << " -- " << traverse -> edge[i] << "[ label = ";
			cout << traverse -> weight[i] << " ];" << endl;
			cout << traverse -> vertex << "[ label = \"" << traverse -> vertex << "\n cost is " << traverse -> cost;
			cout << "\n coming from " << traverse -> fromwhere << "\" ];" << endl;
		}
		if (traverse -> edge.size() == 0) {
			cout << traverse -> vertex << "[ label = \"" << traverse -> vertex << "\n cost is " << traverse -> cost;
			cout << "\n coming from " << traverse -> fromwhere << "\" ];" << endl;
		}
		traverse = traverse -> pointer;
	}
	cout << "}" << endl << endl;
}

bool LinkedListGraph::AddEdge(string source, string target, int num) {
	//first checks that both connections points are in the graph
	if (LinkedListGraph::Search(source)==false) {
		cout << source << " is not in the graph. Conection not added.\n";
		return false;
	}
	if (LinkedListGraph::Search(target)==false) {
		cout << target << " is not in the graph. Connection not added.\n";
		return false;
	}

	Node *curr = head_;
	while (curr -> vertex != source) {
		//finds the node that holds the source of the connection
		curr = curr -> pointer;
	}
	//adds the target connection to the edge of the source connection
	curr -> edge.push_back(target);
	curr -> weight.push_back(num);
	return true;
}

void LinkedListGraph::FirstToGraphviz(string& file) {
	//adds the initial graph to file
	ofstream myfile1;
	myfile1.open(file);
	myfile1 << "graph G {\n";
	myfile1 << "node [shape = square];\n";
	myfile1 << "node [color = blue];\n";
	Node *traverse = head_;
	while (traverse != NULL) {
		//iterates through the list and prints out all the vectors in the graph
		for (int i = 0; i < traverse -> edge.size(); ++i) {
			myfile1 << traverse -> vertex << " -- " << traverse -> edge[i] << "[ label = ";
			myfile1 << traverse -> weight[i] << " ];" << endl;
		}
		traverse = traverse -> pointer;
	}
	myfile1 << "}" << endl;
	myfile1.close();
}

void LinkedListGraph::SecondToGraphviz (string& file) {
	ofstream myfile2;
	myfile2.open(file);
	myfile2 << "graph G {\n";
	myfile2 << "node [shape = square];\n";
	myfile2 << "node [color = blue];\n";
	Node *traverse = head_;
	while (traverse != NULL) {
		//iterates through the list and prints out all the vectors in the graph
		for (int i = 0; i < traverse -> edge.size(); ++i) {
			myfile2 << traverse -> vertex << " -- " << traverse -> edge[i] << "[ label = ";
			myfile2 << traverse -> weight[i] << " ];" << endl;
			myfile2 << traverse -> vertex << "[ label = \"" << traverse -> vertex << "\n cost is " << traverse -> cost;
			myfile2 << "\n coming from " << traverse -> fromwhere << "\" ];" << endl;
		}
		if (traverse -> edge.size() == 0) {
			myfile2 << traverse -> vertex << "[ label = \"" << traverse -> vertex << "\n cost is " << traverse -> cost;
			myfile2 << "\n coming from " << traverse -> fromwhere << "\" ];" << endl;
		}
		traverse = traverse -> pointer;
	}
	myfile2 << "}" << endl;
	myfile2.close();
}

bool LinkedListGraph::FindStatus(string vertex1) {
//returns the status of a vertex, given the vertex
	Node *iterate;
	iterate = head_;
	while (iterate != NULL) {
		if (iterate -> vertex == vertex1) {
			return iterate -> status;
		}
		iterate = iterate -> pointer;
	}
	cout << "ERROR Vertex not found for status" << endl;
	return true;
}

int LinkedListGraph::FindCost (string vertex1) {
//returns the cost associated with vertex1
	Node *iterate;
	iterate = head_;
	while (iterate != NULL) {
		if (iterate -> vertex == vertex1) {
			return iterate -> cost;
		}
		iterate = iterate -> pointer;
	}
	cout << "ERROR Vertex not found for cost" << endl;
	return 0;
}

void LinkedListGraph::ChangeCost(string vertex1, int newcost) {
//changes cost connected to vertex1 to newcost
	Node *iterate;
	iterate = head_;
	while (iterate != NULL) {
		if (iterate -> vertex == vertex1) {
			if (iterate -> cost > newcost) {
				iterate -> cost = newcost;
			}
			else {
				cout << "ERROR cost not calculated correctly" << endl;
			}
		}
		iterate = iterate -> pointer;
	}
}

void LinkedListGraph::ChangeFromWhere(string vertex1, string newfrom) {
//changes fromwhere connected to vertex1 to newfromwhere
	Node *iterate;
	iterate = head_;
	while (iterate != NULL) {
		if (iterate -> vertex == vertex1) {
			iterate -> fromwhere = newfrom;
		}
		iterate = iterate -> pointer;
	}
}

void LinkedListGraph::SetFalse(string vertex1) {
	Node *iterate;
	iterate = head_;
	while (iterate != NULL) {
		if (iterate -> vertex == vertex1) {
			iterate -> status = false;
		}
		iterate = iterate -> pointer;
	}
}

string LinkedListGraph::FindNext() {
//returns the vector with the smalles cost that is also in open
	int mincost = numeric_limits<int>::max();
	Node *iterate;
	iterate = head_;
	string nextcurrent;
	while (iterate != NULL) {
		if (iterate -> status == true && iterate -> cost < mincost) {
			mincost = iterate -> cost;
			nextcurrent = iterate -> vertex;
		}
		iterate = iterate -> pointer;
	}
	return nextcurrent;
}

void LinkedListGraph::Dijkstra() {
	string current;			//holds the current vertex
	string nextcurrent;		//holds the vertex that will be the current
	vector<string> open; 	//vertices not yet minimized
	vector<string> closed;	//vertices already looked at

	Node *createopen;
	createopen = head_;
	for (int i=0; i < vertexcount; i++) {
		//adds all the vertices to open
		open.push_back(createopen -> vertex);
		createopen = createopen -> pointer;
	}

	//arbitrarily pick current vertex and set everything accordingly
	current = open[0];	
	head_ -> cost = 0;

	while (!open.empty()) {
		Node *iterate;
		iterate = head_;

		while (iterate != NULL) {
			if (iterate -> status == true) {	//if the vertex is open
				if (iterate -> vertex == current) {	
					for (int j=0; j < iterate -> edge.size(); j++) {	//look through edges
						if (FindStatus(iterate -> edge[j]) == true)	{	//if the edge is open
							if (FindCost(iterate -> edge[j]) > (iterate -> cost + iterate -> weight[j])) {
								ChangeCost(iterate -> edge[j], (iterate -> cost + iterate -> weight[j]));
								ChangeFromWhere(iterate -> edge[j], current);
							}
						}
					}
				} if (iterate -> vertex != current) {
					for (int j=0; j < iterate -> edge.size(); j++) {	//look through edges
						if (iterate -> edge[j] == current) {	//find any edges = current
							if (iterate -> cost > (iterate -> weight[j] + FindCost(current))) {
								current = current;
								ChangeFromWhere(iterate -> vertex, current);
								ChangeCost(iterate -> vertex, (iterate -> weight[j]) + FindCost(current));
							}
						}
					}
				}
			}
			iterate = iterate -> pointer;
		}
		
		closed.push_back(current);
		for (int i=0; i < open.size(); i++) {
			if (open[i] == current) {
				open.erase(open.begin()+i);
			}
		}
		SetFalse(current);
		current = FindNext();
		iterate = head_;
	}
}