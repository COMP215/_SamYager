/* 
Sam Yager
dijkstra.hpp
*/

#ifndef dijkstra_hpp
#define dijkstra_hpp

using namespace std;

class Node {
public:
	string vertex;	//holds the vertex for this point
	Node* pointer;	//points to the next node in the list
	vector<string> edge;	//holds all the connections this vertex point has to other vertex points
	vector<int> weight;		//holds the weight of each edge

	int cost;		//keeps the cost to get to this point
	string fromwhere;	//keeps track of where the map comes from to calculate the cost
	bool status;		//true means vertex is in open, false for closed
	Node(string word) {vertex=word; pointer=NULL; cost = numeric_limits<int>::max(); status = true; fromwhere=word;};
};

class LinkedListGraph {
	Node* head_;		//head of the graph
	Node* tail_;		//tail of the graph
	int vertexcount;	//count of the number of vertices in the graph
public:
	LinkedListGraph() {head_ = NULL; tail_ = NULL; vertexcount = 0;};	//constructor
	bool AddVertex(string);	//adds a new point to the graph
	bool Search(string);	//searches linked list for a given word
	void PrintGraph(); 	//prints the graph and the mst graph
	void PrintDijkstra(); 	//prints graph wit dijkstras algorithm implemented
	bool AddEdge(string, string, int); //adds a one way connection to the graph
	void FirstToGraphviz(string&);	//adds the graph to a .dot file to be graphed with graphviz
	void SecondToGraphviz(string&);	//adds the graph with dijkstra's algorithm implemented to a .dot file to be graphed
	bool FindStatus(string);	//finds the status of a vertex in the graph
	int FindCost(string);		//finds the cost of a vertex in the graph
	void ChangeCost(string,int);	//changes the cost of the vertex passed to it
	void ChangeFromWhere(string,string);	//changes the first string's fromwhere to the second string
	void SetFalse(string);		//set the vector passed to it to false
	string FindNext();		//returns the vector with the smalles cost that is also in open
	void Dijkstra();		//implements dijkstra's algorithm
};

#endif