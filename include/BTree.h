#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include <iostream>
#include <string>

#include "Review.h"
#include "BTreeNode.h"

class BTree
{
private:
    int t; // Grau mínimo do nó
    int m; // Grau máximo do nó

    BTreeNode* root; // Nó raiz - array de ponteiros para os filhos do nó
    string idIN;

public:
    BTree(int t);
    BTreeNode* search(string k, int* count);
    void insert(infoB k);
    void print();

    void indexReview(int n);
    string getIdIN();
};

#endif // BTREE_H_INCLUDED
