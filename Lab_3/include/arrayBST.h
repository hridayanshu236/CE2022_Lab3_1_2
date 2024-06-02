#define ArrayBST_h
#define MAX_NUM_NODES 128
#include "BSTinterface.h"

// ArrayNode structure
struct ArrayNode
{
    int value;
    bool isOccupied;

    ArrayNode() : value(0), isOccupied(false) {}
    ArrayNode(int value) : value(value), isOccupied(true) {}
};

// ArrayBinarySearchTree class definition
class ArrayBinarySearchTree : public InterfaceBST
{
public:
    ArrayBinarySearchTree();
    ~ArrayBinarySearchTree();
    virtual bool isEmpty();
    virtual void addBST(int data);
    virtual bool removeBST(int keyToDelete);
    virtual bool searchBST(int targetKey);
    void printTree();

private:
    ArrayNode *nodes[MAX_NUM_NODES];
    int findMinIndex(int index);
};