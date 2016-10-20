/*
Sam Yager
kruskalmst.cpp
Uses a linked list implementation of Kruskal's minimum spanning tree algorithm
*/


#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#include "kruskalmst.hpp"

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

void LinkedListGraph::CreateHeap() {
	Node *traverse = head_;		//traverses the graph
	while (traverse != NULL) {
		//creates heaps of all vertex/edge/weight combinations
		for (int i=0; i < traverse -> edge.size(); ++i) {
			Node *temp;
			temp = new Node(traverse -> vertex);
			temp -> edge.resize(1);
			temp -> weight.resize(1);
			temp -> edge[0] = traverse -> edge[i];
			temp -> weight[0] = traverse -> weight[i];

			if (heaphead_ == NULL) {
				//creates first heap of values
				heaphead_ = temp;
				heaptail_ = heaphead_;
			}
			else {
				//puts data in next heap space
				heaptail_ -> pointer = temp;
				heaptail_ = temp;
			}
		} 
		traverse = traverse -> pointer;
	}
}

void LinkedListGraph::KruskalMST() {
	CreateHeap();

	Node *current;			//pointer to traverse through the heap list
	Node *beforecurrent;	//pointer to traverse behind current
	Node *remover;			//pointer to help remove used heaps from list of heaps
	Node *finder;			//pointer to find if vertex or edge is in the tree
	
	int edgecount = 0;	//counts all the edges in the mst
	int numgraphs = 0;	//number of subgraphs, used to keep track and avoid cycles
	bool vertexintree;
	bool edgeintree;
	connections.resize(vertexcount);

	while (edgecount+1 < vertexcount) {
		current = heaphead_;
		int minweight;
		minweight = current -> weight[0];
		while (current != NULL) {
			//traverse through the heap to find the minimum weight
			if (current -> weight[0] < minweight) {
				minweight = current -> weight[0];
				remover = beforecurrent;
			}
			beforecurrent = current;
			current = current -> pointer;
		}

		current = remover -> pointer;
		vertexintree = false;
		edgeintree = false;
		finder = msthead_;

		while (finder != NULL) {
			//see if the vertex or edge is already in the tree
			if (current -> vertex == finder -> vertex || current -> vertex == finder -> edge[0]) 
				vertexintree = true; 
			if (current -> edge[0] == finder -> vertex || current -> edge[0] == finder -> edge[0])  
				edgeintree = true;
			finder = finder -> pointer;
		}


		if (vertexintree == true && edgeintree == true) {
		//if both vertex and edge are in the tree, check if the new weight would create a cycle
			int vertexlocation;	//location of vertex in connections list
			int edgelocation;	//location of vertex in conections list
			for (int i=0; i < connections.size(); i++) {
				for (int j=1; j < connections[i].size(); j++) { 
					if (connections[i][j] == current -> vertex)
						vertexlocation = i;
				}		
			}
			for (int i=0; i < connections.size(); i++) {
				for (int j=1; j < connections[i].size(); j++) { 
					if (connections[i][j] == current -> edge[0])
						edgelocation = i;
				}		
			}

			if (vertexlocation != edgelocation) {
			//this will not cause a cycle and should be added to the mst
				Node *temp;
				temp = new Node (current -> vertex);
				temp -> edge.resize(1);
				temp -> weight.resize(1);
				temp -> edge[0] = current -> edge[0];
				temp -> weight[0] = current -> weight[0];

				msttail_ -> pointer = temp;
				msttail_ = temp;
				edgecount++;

				//fix connections list by combining vertexlocation and edgelocation
				for (int i=0; i < connections[edgelocation].size(); i++) {
					connections[vertexlocation].push_back(connections[edgelocation][i]);
				}
				connections[edgelocation].resize(0);
			}

		} else {
			//if either vertex or edge are not in the tree, add it to the tree
			Node *temp;
			temp = new Node (current -> vertex);
			temp -> edge.resize(1);
			temp -> weight.resize(1);
			temp -> edge[0] = current -> edge[0];
			temp -> weight[0] = current -> weight[0];

			if (msthead_ == NULL) {
				//adds the current heap to the mst if the mst is empty
				msthead_ = temp;
				msttail_ = msthead_;
				//adds to list of connections
				connections[0].push_back(current -> vertex);
				connections[0].push_back(current -> edge[0]);
				numgraphs++;
			}
			else {
				//add the current heap to end of the mst
				msttail_ -> pointer = temp;
				msttail_ = temp;

				if (vertexintree == true && edgeintree == false) {
					for (int i=0; i < connections.size(); i++) {
						for (int j=0; j < connections[i].size(); j++) {
							if (current -> vertex == connections[i][j])
								connections[i].push_back(current -> edge[0]);
						}
					}
				} else if (vertexintree == false && edgeintree == true) {
					for (int i=0; i < connections.size(); i++) {
						for (int j=0; j < connections[i].size(); j++) {
							if (current -> edge[0] == connections[i][j])
								connections[i].push_back(current -> vertex);
						}
					}
				} else { // if neither the vertex nor the edge are in the tree
					numgraphs++;
					connections[numgraphs].push_back(current -> vertex);
					connections[numgraphs].push_back(current -> edge[0]);
				}
			}
			edgecount++;
		}

		//remove current heap whether it was added to the graph or not
		remover -> pointer = current -> pointer;
	}
}