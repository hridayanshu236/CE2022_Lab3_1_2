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
            std::cout << "Tree is full, cannot add more nodes." << std::endl;
        }
    }
}

// Find the index of the minimum value in the subtree rooted at index
int ArrayBinarySearchTree::findMinIndex(int index) {
    while (index < MAX_NUM_NODES && nodes[2 * index + 1] != nullptr) {
        index = 2 * index + 1;  // Move to left child
    }
    return index;
}

bool ArrayBinarySearchTree::removeBST(int keyToDelete) {
    int index = 0;
    int parentIndex = -1;
    bool isLeftChild = false;

    // Find the node to be deleted and its parent
    while (index < MAX_NUM_NODES && nodes[index] != nullptr) {
        if (keyToDelete == nodes[index]->value) {
            break;
        } else if (keyToDelete < nodes[index]->value) {
            parentIndex = index;
            isLeftChild = true;
            index = 2 * index + 1;  // Left child index
        } else {
            parentIndex = index;
            isLeftChild = false;
            index = 2 * index + 2;  // Right child index
        }
    }

    if (index >= MAX_NUM_NODES || nodes[index] == nullptr) {
        return false;  // Node not found
    }

    // Case 1: Node to be deleted has no children (leaf node)
    if (nodes[2 * index + 1] == nullptr && nodes[2 * index + 2] == nullptr) {
        delete nodes[index];
        nodes[index] = nullptr;
    }
    // Case 2: Node to be deleted has one child
    else if (nodes[2 * index + 1] == nullptr || nodes[2 * index + 2] == nullptr) {
        int childIndex = (nodes[2 * index + 1] != nullptr) ? 2 * index + 1 : 2 * index + 2;

        delete nodes[index];
        nodes[index] = nodes[childIndex];
        nodes[childIndex] = nullptr;
    }
    // Case 3: Node to be deleted has two children
    else {
        int minIndex = findMinIndex(2 * index + 2);  // Find the minimum node in the right subtree
        nodes[index]->value = nodes[minIndex]->value;  // Replace value with the minimum value

        // Recursively delete the minimum node in the right subtree
        int minParentIndex = (minIndex - 1) / 2;
        if (nodes[minIndex] != nullptr) {
            if (minIndex == 2 * minParentIndex + 1) {
                nodes[minParentIndex]->isOccupied = false;
            } else if (minIndex == 2 * minParentIndex + 2) {
                nodes[minParentIndex]->isOccupied = false;
            }
            delete nodes[minIndex];
            nodes[minIndex] = nullptr;
        }
    }

    return true;
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
// Print the tree
void ArrayBinarySearchTree::printTree() {
    for (int i = 0; i < MAX_NUM_NODES; ++i) {
        if (nodes[i] != nullptr) {
            std::cout << "Index " << i << ": " << nodes[i]->value << std::endl;
        }
    }
}