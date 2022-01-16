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
    int t; // Grau m�nimo do n�
    int m; // Grau m�ximo do n�

    infoB* keys; // Array com as chaves do N�
    BTreeNode** Node; // Array de ponteiros para os filhos do n�
    int n; // N�mero de Chaves atuais (n�s dentro de um n�)
    bool leaf; // Define se o N� � uma folha ou n�o

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
