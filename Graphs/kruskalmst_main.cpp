/*
Sam Yager
kruskalmst_main.cpp
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#include "kruskalmst.hpp"

int main () {
	LinkedListGraph graph1;
	string file1, file2;
	file1 = "graph.dot";
	file2 = "graph2.dot";

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

	graph1.KruskalMST();
	graph1.PrintGraph();
	graph1.ToGraphviz(file1, file2);

	return 0;
}