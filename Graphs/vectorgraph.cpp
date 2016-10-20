/*
Sam Yager & Phuntsho Norbu
Project started: Oct 4 2016
1. Implement a basic graph that you can add things to
	code should create a dot file that can be used in 
	Graphviz to create a visualization
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


class Graph {
private:
	vector<string> vertices;			//our vector for vertices
	vector<vector<string> > edges;		//our vector of vectors of edges
	vector<vector<int> > labels;		//labels for each edge
	int count;							//keeps a count for the size of the edges vector
public:	
	bool AddVertex(string);				//adds a vertice to the graph
	bool AddEdge(string, string, int);	//adds edge to graph
	void Print();					//prints the graph
	void WriteToFile();				//writes graph to dot file
	Graph() {};
};

bool Graph::AddVertex (string data) {
//adds the data to the vertices vector and increases the size of the edges vector simultaneously
	vertices.push_back(data);
	count++;
	return false;
}

bool Graph::AddEdge (string first, string last, int num) {
//adds an connection between two vertices with a label
//the label is a number quantifying the size of the connection
	for (int i=0; i < vertices.size(); ++i) {
		if (first == vertices[i]) {
			edges.resize(count);
			edges[i].push_back(last);
			labels.resize(count);
			labels[i].push_back(num);
			return true;
		} 
	}
	cout << "Vertice " << first << " not found in graph\n";
	return false;
}

void Graph::Print() {
//prints the graph in the same format as will output to a .dot file for Graphviz
	cout << "graph G {\n";
	cout << "node [shape = square];\n";
	cout << "node [color = blue];\n";
	for (int i=0; i < vertices.size(); ++i) {
		for (int j=0; j < edges[i].size(); ++j) {
			cout << vertices[i] << " -- " << edges[i][j] << "[ label = " << labels[i][j] <<" ];\n";
		}
	}
	cout << "}" << endl;
}

void Graph::WriteToFile() {
//writes the graph to a .dot file to be visualized by Graphviz
	ofstream myfile;
	myfile.open("graph.dot");
	myfile << "graph G {\n";
	myfile << "node [shape = square];\n";	//shape of the vertices
	myfile << "node [color = blue];\n";		//adds color to the vertices
	for (int i=0; i < vertices.size(); ++i) {
		for (int j=0; j < edges[i].size(); ++j) {
			myfile << vertices[i] << " -- " << edges[i][j] << "[ label = " << labels[i][j] <<" ];\n";
		}
	}
	myfile << "}" << endl;
	myfile.close();
}


int main () {
	Graph graph1;

	graph1.AddVertex("1");
	graph1.AddVertex("2");
	graph1.AddVertex("3");
	graph1.AddVertex("4");
	graph1.AddVertex("5");
	graph1.AddVertex("6");

	graph1.AddEdge("1","2",7);
	graph1.AddEdge("2","3",10);
	graph1.AddEdge("3","4",3);
	graph1.AddEdge("2","6",1);
	graph1.AddEdge("3","5",4);
	graph1.AddEdge("6","5",6);
	graph1.AddEdge("5","4",4);
	graph1.AddEdge("1","3",2);

	graph1.Print();
	graph1.WriteToFile();
	return 0;
}