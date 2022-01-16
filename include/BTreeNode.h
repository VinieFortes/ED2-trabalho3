#ifndef BTREENODE_H_INCLUDED
#define BTREENODE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct infoB
{
  string id = "";
  int pos = -1;

  infoB(string review_id, int pos)
  {
    this->id = review_id;
    this->pos = pos;
  }

  infoB(){};
};

class BTreeNode
{
private:
    int t; // Grau mínimo do nó
    int m; // Grau máximo do nó

    infoB* keys; // Array com as chaves do Nó
    BTreeNode** Node; // Array de ponteiros para os filhos do nó
    int n; // Número de Chaves atuais (nós dentro de um nó)
    bool leaf; // Define se o Nó é uma folha ou não

public:
    BTreeNode(int t, bool leaf);
    void insertEmpty(infoB k);
    void insertSplitChild(int index, BTreeNode* overflow);
    BTreeNode* search(string k, int* count);
    void printNode();

    infoB getKeys(int n);
    void setKeys(infoB k);
    int getN();
    void setN(int n);
    BTreeNode* getNode(int i);
    void setNode(int i, BTreeNode* root);
};

#endif // BTREENODE_H_INCLUDED
