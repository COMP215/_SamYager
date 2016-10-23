/*
Sam Yager
primmst.hpp
*/

#ifndef primmst_hpp
#define primmst_hpp

using namespace std;

class Node {
public:
	string vertex;	//holds the vertex for this point
	Node* pointer;	//points to the next node in the list
	vector<string> edge;	//holds all the connections this vertex point has to other vertex points
	vector<int> weight;		//holds the weight of each edge
	Node(string word) {vertex=word; pointer=NULL;};	//constructor
};

class LinkedListGraph {
	Node* head_;		//head of the graph
	Node* tail_;		//tail of the graph
	Node* heaphead_;		//head of heap
	Node* heaptail_;		//tail of heap
	Node* msthead_;			//head of the minimum spanning tree graph
	Node* msttail_;			//tail of the minimum spaning tree graph
	int vertexcount;		//count of the number of vertices in the graph
public:
	LinkedListGraph() {head_ = NULL; tail_ = NULL; heaphead_ = NULL; heaptail_ = NULL; vertexcount = 0;};	//constructor
	bool AddVertex(string);	//adds a new point to the graph
	bool Search(string);	//searches linked list for a given word
	void PrintGraph(); 	//prints the graph and the mst graph
	bool AddEdge(string, string, int); //adds a one way connection to the graph
	void ToGraphviz(string&, string&);	//adds the graph and the mst graph to two seperate .dot files to be graphed with graphviz
	void PrimMST();		//creates a minimum spanning tree using Kruskal's algorithm
};

#endif