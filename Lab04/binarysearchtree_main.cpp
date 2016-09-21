/*
Sam Yager
binarysearchtree_main.cpp
*/

#include <iostream>
#include "binarysearchtree.hpp"

int main(int argc, const char * argv[]) {
    BinarySearchTree* people_names = new BinarySearchTree();

    people_names->Search("hi");

    people_names->Insert("gousie");
    people_names->Insert("bloch");
    people_names->Insert("armstrong");
    people_names->Insert("decoste");


    people_names->Search("bloch");
    people_names->Search("hey");

    std::cout << "Hello, World!\n";
    return 0;
}