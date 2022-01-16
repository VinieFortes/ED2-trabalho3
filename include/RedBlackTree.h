#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <string>

#include "../include/Review.h"

using namespace std;

struct Data
{
    string id;
    int pos;

    Data(string id, int position)
    {
        this->id = id;
        this->pos = position;
    }

    Data() {};
};

struct Node
{
    Data data;
    bool color;
    Node* left, * right, * parent;

    // Constructor
    Node(Data data)
    {
        this->data = data;
        left = right = parent = NULL;
        this->color = 1;
    }
};

class RedBlackTree
{
public:
    RedBlackTree() { root = NULL; }
    ~RedBlackTree() {};
    void insert(Data& data);
    void indexReview(int n);
    void order();
    Node* search(string name, int* count);
    string getRandomID();

private:
    Node* root;
    string RandomID;

protected:
    void rotateLeft(Node*&, Node*&);
    void rotateRight(Node*&, Node*&);
    void rebalance(Node*&, Node*&);
};

#endif
