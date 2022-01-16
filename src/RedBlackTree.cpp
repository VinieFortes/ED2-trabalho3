#include "../include/RedBlackTree.h"

void orderAux(Node* root)
{
    if (root == NULL)
        return;

    orderAux(root->left);
    cout << root->data.id << endl;
    orderAux(root->right);
}

void RedBlackTree::order() { orderAux(root); }

Node* InsertAux(Node* root, Node* pt)
{
    if (root == NULL)
        return pt;

    if (pt->data.id < root->data.id)
    {
        root->left = InsertAux(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data.id > root->data.id)
    {
        root->right = InsertAux(root->right, pt);
        root->right->parent = root;
    }

    /* return the (unchanged) node pointer */
    return root;
}

void RedBlackTree::rotateLeft(Node*& root, Node*& pt)
{
    Node* pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void RedBlackTree::rotateRight(Node*& root, Node*& pt)
{
    Node* pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

void RedBlackTree::rebalance(Node*& root, Node*& pt)
{
    Node* parent_pt = NULL;
    Node* grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != 0) &&
        (pt->parent->color == 1))
    {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /*  Case : A */
        if (parent_pt == grand_parent_pt->left)
        {

            Node* uncle_pt = grand_parent_pt->right;

            /* Case : 1 */
            if (uncle_pt != NULL && uncle_pt->color ==
                1)
            {
                grand_parent_pt->color = 1;
                parent_pt->color = 0;
                uncle_pt->color = 0;
                pt = grand_parent_pt;
            }

            else
            {
                /* Case : 2 */
                if (pt == parent_pt->right)
                {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3 */
                rotateRight(root, grand_parent_pt);
                parent_pt->color = 0;
                grand_parent_pt->color = 1;
                pt = parent_pt;
            }
        }

        /* Case : B */
        else
        {
            Node* uncle_pt = grand_parent_pt->left;

            /*  Case : 1 */
            if ((uncle_pt != NULL) && (uncle_pt->color == 1))
            {
                grand_parent_pt->color = 1;
                parent_pt->color = 0;
                uncle_pt->color = 0;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2 */
                if (pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3 */
                rotateLeft(root, grand_parent_pt);
                parent_pt->color = 0;
                grand_parent_pt->color = 1;
                pt = parent_pt;
            }
        }
    }

    root->color = 0;
}

void RedBlackTree::insert(Data& data)
{
    Node* pt = new Node(data);

    root = InsertAux(root, pt);

    rebalance(root, pt);
}

void RedBlackTree::indexReview(int n)
{
    ReviewPosition* list = Review::getReviewPosition(n);

    for (int i = 0; i < n; i++)
    {

        Data data = Data(list[i].id, list[i].pos);
        this->insert(data);
    }

    int idxRandom = rand() % n;
    RandomID = list[idxRandom].id;
}

Node* searchAux(Node* root, string id, int* count)
{
    *count = *count + 1;
    if (root == NULL || id == root->data.id)
    {
        return root;
    }

    *count = *count + 1;
    if (id < root->data.id)
    {
        return searchAux(root->left, id, count);
    }
    else
    {
        return searchAux(root->right, id, count);
    }
}

Node* RedBlackTree::search(string id, int* count)
{
    *count = 0;
    return searchAux(root, id, count);
}

string RedBlackTree::getRandomID()
{
    return RandomID;
}