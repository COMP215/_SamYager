# _SamYager

File name: vectorgraph.cpp
This is a file that creates a graph using Graphviz and vectors for implementation.
Type the following into a terminal window to create the desired graph:
  g++ vectorgraph.cpp
  ./a.out
  dot -Tpng graph.dot > output.png


File names: primmst.cpp primmst_main.cpp
	Includes primmst.hpp
This is a file that creates a minimum spanning tree using Prim's Algorithm
This program ouputs two graphs for Graphviz and uses a linked list implementation
Type the following into a terminal window to create the desired graph:
	g++ primmst.cpp primmst_main.cpp
	./a.out
	dot -Tpng graph.dot > output.png
	dot -Tpng graph2.dot > output2.png

The file named output.png will contain the original graph and the file named output2.png will contain the minimum spanning tree produced by Prim's algorithm


File names: kruskalmst.cpp kruskalmst_main.cpp
	Includes kruskalmst.hpp
This is a file that creates a minimum spanning tree using Kruskal's Algorithm
This program ouputs two graphs for Graphviz and uses a linked list implementation
Type the following into a terminal window to create the desired graph:
	g++ kruskalmst.cpp kruskalmst_main.cpp
	./a.out
	dot -Tpng graph.dot > output.png
	dot -Tpng graph2.dot > output2.png

The file named output.png will contain the original graph and the file named output2.png will contain the minimum spanning tree produced by Kruskal's algorithm
