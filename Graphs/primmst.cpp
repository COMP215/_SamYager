/*
Sam Yager
primmst.cpp
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#include "primmst.hpp"

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

	//prints the minimum spanning tree graph
	cout << "graph G {\n";
	cout << "node [shape = square];\n";
	cout << "node [color = blue];\n";
	traverse = msthead_;
	while (traverse != NULL) {
		//traverses the list and prints out all the vectors in the graph
		for (int i = 0; i < traverse -> edge.size(); ++i) {
			cout << traverse -> vertex << " -- " << traverse -> edge[i] << "[ label = ";
			cout << traverse -> weight[i] << " ];" << endl;
		}
		traverse = traverse -> pointer;
	}
	cout << "}" << endl;
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

void LinkedListGraph::ToGraphviz(string& file1, string& file2) {
	//adds the initial graph to file1
	ofstream myfile1;
	myfile1.open(file1);
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

	//adds the minimum spanning tree to file2
	ofstream myfile2;
	myfile2.open(file2);
	myfile2 << "graph G {\n";
	myfile2 << "node [shape = square];\n";
	myfile2 << "node [color = blue];\n";
	traverse = msthead_;
	while (traverse != NULL) {
		//interates through the list and prints out all the vectors in the mst graph
		for (int i = 0; i < traverse -> edge.size(); ++i) {
			myfile2 << traverse -> vertex << " -- " << traverse -> edge[i] << "[ label = ";
			myfile2 << traverse -> weight[i] << " ];" << endl;
		}
		traverse = traverse -> pointer;
	}
	myfile2 << "}" << endl;
	myfile2.close();
}

void LinkedListGraph::PrimMST() {
	//redo adding edges so the edge is shown from source to target and target to source

	vector<string> closed;		//vertice already used in mst 
	vector<string> open;		//vertices not yet in mst

	Node *temp;
	temp = head_;
	for (int i=0; i < vertexcount; i++) {
		//adds all the vertices to open
		open.push_back(temp -> vertex);
		temp = temp -> pointer;
	}

	string minvertex = open[0];	//arbitrarily pick current vertex
	string minedge;				//holder for smallest edge to be found later
	closed.push_back(open[0]);
	open.erase(open.begin()+0);


	while (!open.empty()) { //while open is not empty, meaning not all the vertices are not in the mst
		Node *iterate = head_;
		int minweight = numeric_limits<int>::max();		//holds the minimum weight

		for (int j=0; j < closed.size(); j++) {	//look through all the closed values
			string currentvertex = closed[j];
			while (iterate != NULL) { //find the smallest weight connected with current closed vertex
				if (iterate -> vertex == currentvertex) {	//find current closed vertex in graph
					for (int i=0; i < iterate -> weight.size(); i++) {	
						if (iterate -> weight[i] < minweight) {	//if it finds a new smallest weight
							for (int m=0; m < open.size(); m++) {
								if (open[m] == iterate -> edge[i]) {	
								//if the edge conencted to the smallest wight is open, assign this as the next mst edge
									minweight = iterate -> weight[i];
									minvertex = currentvertex;
									minedge = iterate -> edge[i];
								}
							}
						}
					}
				} if (iterate -> vertex != currentvertex) {
					for (int i=0; i < iterate -> edge.size(); i++) {	//look through edges for the currentvertex
						if (iterate -> edge[i] == currentvertex && iterate -> weight[i] < minweight) {	//if the edge is the currentvertex & it finds a new smallest weight
							for (int m=0; m < open.size(); m++) { //look through open to see if the edge is there
								if (open[m] == iterate -> vertex) {
									//if the vertex is open, assign this as the next mst vertex
									minweight = iterate -> weight[i];
									minvertex = iterate -> edge[i];
									minedge = iterate -> vertex;
								}
							}
						}
					}
				}
				iterate = iterate -> pointer;
			}
			iterate = head_;
		}

		//add new connection to the mst
		Node *temp;
		temp = new Node (minvertex);
		temp -> edge.resize(1);
		temp -> weight.resize(1);
		temp -> edge[0] = minedge;
		temp -> weight[0] = minweight;
		if (msthead_ == NULL) {
			msthead_ = temp;
			msttail_ = msthead_;
		} else {
			msttail_ -> pointer = temp;
			msttail_ = temp;
		}

		//move new added vertex to closed list and delete from open list
		closed.push_back(minedge);
		for (int i=0; i < open.size(); i++) {
			if (open[i] == minedge) {
				open.erase(open.begin()+i);
			}
		}
		minvertex = minedge;
	}
}

