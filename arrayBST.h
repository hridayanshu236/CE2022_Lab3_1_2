#define ArrayBST_h
#define MAX_NUM_NODES 128
#include "BSTinterface.h"

struct ArrayNode{
    int value;
    ArrayNode(int value):value(value){}
};


class ArrayBinarySearchTree : public InterfaceBST
{
public:
    ArrayBinarySearchTree();
    ~ArrayBinarySearchTree();
    virtual bool isEmpty();
    virtual void addBST(int data);
    virtual bool removeBST(int keyToDelete);
    virtual bool searchBST(int targetKey);

private:
    ArrayNode* nodes[3];
};