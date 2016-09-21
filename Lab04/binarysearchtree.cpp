/*
Sam Yager
binarysearchtree.cpp
*/

#include "binarysearchtree.hpp"
#include <string>
#include <iostream>
using namespace std;

Node::Node(string data) {
    data_ = data;
    left_ = NULL;
    right_ = NULL;
}

BinarySearchTree::BinarySearchTree() {
    root_ = NULL;
}

bool BinarySearchTree::Insert(string data) {
    if (root_ == NULL) {
        // Empty tree, make a root
        root_ = new Node(data);
        return true;
    } else {
        // Non-empty tree, find correct position for data
        Node* curr = root_;
        while (curr != NULL) {
            if (data == curr->data_) {
                // Data already in tree, fail to insert
                return false;
            } else if (data < curr->data_) {
                // Lexicographically lesser, find location to the left
                if (curr->left_ == NULL) {
                    curr->left_ = new Node(data);
                    return true;
                } else {
                    curr = curr->left_;
                }
            } else {
                // Lexicographically greater, find location to the right
                if (curr->right_ == NULL) {
                    curr->right_ = new Node(data);
                    return true;
                } else {
                    curr = curr->right_;
                }
            }
        }
    }
    return false;
}

bool BinarySearchTree::Search(string data) {
    if (root_ == NULL) {
        // Empty tree, return false
        root_ = new Node(data);
        cout << root_->data_ << " is not in the tree!" << endl;
        return false; 
    } else {
        // Non-empty tree, look for the data
        Node* curr = root_;
        while (curr != NULL) {
            if (data == curr->data_) {
                // Data already in tree, return true
                cout << curr->data_ << " is in the tree!" << endl;
                return true;
            } else if (data < curr->data_) {
                // Lexicographically lesser, go left
                curr = curr->left_;
            } else {
                // Lexicographically greater, go right
                    curr = curr->right_;
            }
        }
        cout << data << " is not in the tree!" << endl;
        return false;
    }
    
}

bool BinarySearchTree::Delete(string data) {
    if (BinarySearchTree::Search(data) == false) {
        cout << data << " cannot be deleted because it is not in the tree" << endl;
        return false;
    }
    
    return false;
}





