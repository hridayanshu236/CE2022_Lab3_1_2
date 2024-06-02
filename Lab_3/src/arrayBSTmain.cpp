#include<iostream>
#include"../include/arrayBST.h"
// Main function to test the ArrayBinarySearchTree
int main() {
    ArrayBinarySearchTree bst;
    
    std::cout << "Is the tree empty? " << (bst.isEmpty() ? "Yes" : "No") << std::endl;

    bst.addBST(10);
    bst.addBST(5);
    bst.addBST(15);
    bst.addBST(11);
    bst.addBST(13);
    bst.printTree();
    std::cout << "Is the tree empty? " << (bst.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "Searching for 10: " << (bst.searchBST(10) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 7: " << (bst.searchBST(7) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 5: " << (bst.searchBST(5) ? "Found" : "Not Found") << std::endl;
    bst.removeBST(5);  
    bst.removeBST(11);  
    std::cout << "Searching for 5: " << (bst.searchBST(5) ? "Found" : "Not Found") << std::endl;
    bst.printTree();
    return 0;
}