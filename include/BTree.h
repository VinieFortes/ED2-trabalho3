#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include <iostream>
#include <string>

#include "Review.h"
#include "BTreeNode.h"

class BTree
{
private:
    int t; // Grau m�nimo do n�
    int m; // Grau m�ximo do n�

//int comparacaoBusca;
    //int insercaoBusca;

    BTreeNode* root; // N� raiz - array de ponteiros para os filhos do n�
    string idIN;

public:
    BTree(int t);
    BTreeNode* search(string k, int* count);
    void insert(infoB k);
    void print();

    //int getComparacaoBusca() {return this->comparacaoBusca;};
        //int getInsercaoBusca() {return this->insercaoBusca;};

    void indexReview(int n);
    string getIdIN();
};

#endif // BTREE_H_INCLUDED
