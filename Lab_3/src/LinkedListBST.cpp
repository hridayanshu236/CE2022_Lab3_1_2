#include <iostream>
#include "../include/LinkedListBST.h"

using namespace std;

LinkedBST::LinkedBST() : root(nullptr) {}
LinkedBST::~LinkedBST()
{
    delete root;
}

bool LinkedBST::isEmpty()
{
    return root == nullptr;
}

void LinkedBST::addBST(int data)
{
    Node *newNode = new Node(data);
    if (isEmpty())
    {
        root = newNode;
        return;
    }

    Node *temp = root;
    Node *parent = nullptr;
    while (temp != nullptr)
    {
        parent = temp;
        if (data < temp->key)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
    }
    if (data < parent->key)
    {
        parent->leftChild = newNode;
    }
    else
    {
        parent->rightChild = newNode;
    }
    newNode->parent = parent;
}

bool LinkedBST::removeBST(int keyToDelete)
{
    Node *temp = root;
    Node *parent = nullptr;
    while (temp != nullptr && temp->key != keyToDelete)
    {
        parent = temp;
        if (keyToDelete < temp->key)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
    }

    if (temp == nullptr)
    {
        return false; // Key not found
    }
    // if not this, then key is in temp

    // Case 1: Node has no children
    if (temp->leftChild == nullptr && temp->rightChild == nullptr)
    {
        if (parent == nullptr)
        {
            root = nullptr;
        }
        else if (parent->leftChild == temp)
        {
            parent->leftChild = nullptr;
        }
        else
        {
            parent->rightChild = nullptr;
        }
        delete temp;
    }
    // Case 2: Node has one child
    else if (temp->leftChild == nullptr)
    {
        if (parent == nullptr)
        {
            root = temp->rightChild;
        }
        else if (parent->leftChild == temp)
        {
            parent->leftChild = temp->rightChild;
        }
        else
        {
            parent->rightChild = temp->rightChild;
        }
        delete temp;
    }
    else if (temp->rightChild == nullptr)
    {
        if (parent == nullptr)
        {
            root = temp->leftChild;
        }
        else if (parent->leftChild == temp)
        {
            parent->leftChild = temp->leftChild;
        }
        else
        {
            parent->rightChild = temp->leftChild;
        }
        delete temp;
    }
    // Case 3: Node has two children
    else
    {
        Node *successor = temp->rightChild;
        Node *successorParent = temp;
        while (successor->leftChild != nullptr)
        {
            successorParent = successor;
            successor = successor->leftChild;
        }

        if (successorParent != temp)
        {
            successorParent->leftChild = successor->rightChild;
        }
        else
        {
            successorParent->rightChild = successor->rightChild;
        }

        temp->key = successor->key;
        delete successor;
    }

    return true;
}

bool LinkedBST::searchBST(int targetKey)
{
    Node *temp = root;
    while (temp != nullptr)
    {
        if (targetKey == temp->key)
        {
            return true;
        }
        else if (targetKey < temp->key)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
    }
    return false;
}
void LinkedBST::inorder(Node *node)
{
    if (node == nullptr)
        return;
    inorder(node->leftChild);
    cout << "Node data: " << node->key << endl;
    inorder(node->rightChild);
}
void LinkedBST::display()
{
    cout << endl;
    inorder(root);
    cout << endl;
}
