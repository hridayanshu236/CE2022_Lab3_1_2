#include <iostream>
#include "LinkedListBST.h"
using namespace std;

// Main function to test the LinkedBST
int main()
{
    LinkedBST bst;

    cout << "Is the tree empty? " << (bst.isEmpty() ? "Yes" : "No") << endl;

    bst.addBST(10);
    bst.addBST(5);
    bst.addBST(15);
    bst.addBST(3);
    bst.addBST(7);
    bst.addBST(12);
    bst.addBST(18);
    cout << "Is the tree empty? " << (bst.isEmpty() ? "Yes" : "No") << endl;
    bst.display();
    cout << "Searching for 10: " << (bst.searchBST(10) ? "Found" : "Not Found") << endl;
    cout << "Searching for 7: " << (bst.searchBST(7) ? "Found" : "Not Found") << endl;
    cout << "Removing 5: " << (bst.removeBST(5) ? "Success" : "Fail") << endl;
    bst.display();
    cout << "Searching for 5: " << (bst.searchBST(5) ? "Found" : "Not Found") << endl;
    cout << "Removing 10: " << (bst.removeBST(10) ? "Success" : "Fail") << endl;
    bst.display();
    cout << "Searching for 10: " << (bst.searchBST(10) ? "Found" : "Not Found") << endl;
    return 0;
}
