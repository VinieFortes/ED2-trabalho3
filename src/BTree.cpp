#include "../include/BTree.h"

BTree::BTree(int t)
{
    root = NULL;
    this->t = t;

    this->m = 2 * t;
}

/**
 * Função que chama a impressão da árvore
*/
void BTree::print()
{
    cout << "Impressao:" << endl;
    if (root != NULL)
    {
        cout << "em Ordem -> ";
        root->printNode();
    }
}

/**
 * @param k, chave a ser buscada
 * Função que chama a busca na árvore
*/
BTreeNode* BTree::search(string k, int* count)
{
    *count = 0;
    if (root == NULL)
        return NULL;

    BTreeNode* result = root->search(k, count);

    return result;
}

/**
 * @param k, chave a ser inserida
 * Função de inserção na árvore
 * verficia se a arvore está vazia ou contem algum nó, podendo chamar a inserção para nó
 * com espaço ou inserção com divisão
*/
void BTree::insert(infoB k)
{
    if (root == NULL)
    {
        root = new BTreeNode(t, true);
        root->setKeys(k);
        root->setN(1);
    }
    else
    {
        /**
         * verifica se o nó tem espaço,
         * se sim realiza a inserção normal, se não chama a inserção por divisão de nó
        */
        if (root->getN() != m - 1)
        {
            root->insertEmpty(k);
        }
        else
        {
            BTreeNode* newRoot = new BTreeNode(t, false);

            newRoot->setNode(0, root);
            newRoot->insertSplitChild(0, root);

            int i = 0;
            if (newRoot->getKeys(0).id < k.id)
                i++;

            newRoot->getNode(i)->insertEmpty(k);

            root = newRoot;
        }
    }
}

void BTree::indexReview(int n)
{
    ReviewPosition* list = Review::getReviewPosition(n);

    for (int i = 0; i < n; i++)
    {
        infoB data = infoB(list[i].id, list[i].pos);
        this->insert(data);
    }
    int idxRandom = rand() % n;
    idIN = list[idxRandom].id;
}


string BTree::getIdIN()
{
    return idIN;
}