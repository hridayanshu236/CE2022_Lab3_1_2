#include <iostream>
#include "LinkedListBST.h"
using namespace std;

int main()
{
    InterfaceBST *bst = new LinkedBST();
    cout << "Is the tree empty? " << (bst->isEmpty() ? "Yes" : "No") << endl;

    bst->addBST(5);
    bst->addBST(3);
    bst->addBST(7);
    bst->addBST(2);
    bst->addBST(4);
    bst->addBST(6);

    cout << "Does the tree contain 4? " << (bst->searchBST(4) ? "Yes" : "No") << endl;
    cout << "Does the tree contain 9? " << (bst->searchBST(9) ? "Yes" : "No") << endl;

    bst->removeBST(7);
    cout << "Does the tree contain 7 after removal? " << (bst->searchBST(7) ? "Yes" : "No") << endl;

    delete bst;
    return 0;
}