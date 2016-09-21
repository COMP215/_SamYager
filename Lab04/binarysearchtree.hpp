/*
Sam Yager
binarysearchtree.hpp
*/

#ifndef binarysearchtree_hpp
#define binarysearchtree_hpp

#include <stdio.h>
#include <string>

class Node {
public:
    std::string data_;
    Node* left_;
    Node* right_;
    Node(std::string);
};

class BinarySearchTree {
    Node* root_;
public:
    BinarySearchTree();
    bool Insert(std::string);
    bool Search(std::string);
    bool Delete(std::string);
};

#endif /* binarysearchtree_hpp */