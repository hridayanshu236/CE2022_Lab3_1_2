#include<iostream>
#include"../include/arrayBST.h"

// Constructor
ArrayBinarySearchTree::ArrayBinarySearchTree() {
    for (int i = 0; i < MAX_NUM_NODES; ++i) {
        nodes[i] = nullptr;
    }
}

// Destructor
ArrayBinarySearchTree::~ArrayBinarySearchTree() {
    for (int i = 0; i < MAX_NUM_NODES; ++i) {
        if (nodes[i] != nullptr) {
            delete nodes[i];
        }
    }
}

// Check if the tree is empty
bool ArrayBinarySearchTree::isEmpty() {
    return nodes[0] == nullptr;
}

// Add a node to the BST
void ArrayBinarySearchTree::addBST(int data) {
    if (isEmpty()) {
        nodes[0] = new ArrayNode(data);
    } else {
        int index = 0;
        while (index < MAX_NUM_NODES && nodes[index] != nullptr) {
            if (data < nodes[index]->value) {
                index = 2 * index + 1;  // Left child index
            } else if (data > nodes[index]->value) {
                index = 2 * index + 2;  // Right child index
            } else {
                // Duplicate value, not adding
                return;
            }
        }
        if (index < MAX_NUM_NODES) {
            nodes[index] = new ArrayNode(data);
        } else {
            std::cerr << "Tree is full, cannot add more nodes." << std::endl;
        }
    }
}

// Remove a node from the BST
bool ArrayBinarySearchTree::removeBST(int keyToDelete) {
   
}

// Search for a node in the BST
bool ArrayBinarySearchTree::searchBST(int targetKey) {
    int index = 0;
    while (index < MAX_NUM_NODES && nodes[index] != nullptr) {
        if (targetKey == nodes[index]->value) {
            return true;
        } else if (targetKey < nodes[index]->value) {
            index = 2 * index + 1;  // Left child index
        } else {
            index = 2 * index + 2;  // Right child index
        }
    }
    return false;
}
