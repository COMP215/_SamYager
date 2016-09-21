/*
Sam Yager
linkedlist_main.cpp
*/


#include <iostream>
#include "LinkedList.hpp"

int main() {
	LinkedList List;
	List.Search("17");

	List.AddToTail("5");
	List.AddToTail("7");
	List.AddToHead("3");
	List.PrintList();

	List.Search("5");
	List.Search("8");

	List.Delete("5");
	List.Delete("4");
	List.PrintList();
	return 0;
}