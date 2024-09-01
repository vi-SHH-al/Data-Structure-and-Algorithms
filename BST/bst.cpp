#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d < root->data)
        root->left = insert(root->left, d);
    else
        root->right = insert(root->right, d);

    return root;
}

void bulid(Node *&root)
{
    int d;
    cin >> d;

    while (d != -1)
    {
        root = insert(root, d);
        cin >> d;
    }
}

Node *find_predecessor(Node *root)
{
    if (root == NULL)
        return root;

    Node *temp = root->left;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *find_successor(Node *root)
{
    if (root == NULL)
        return root;

    Node *temp = root->right;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}
Node *deleteInBST(Node *root, int key)
{

    if (root == NULL)
        return NULL;

    if (key == root->data)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        } // 1 child
        if (root->left != NULL && root->right == NULL)
        { // left child exist only
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL && root->left == NULL)
        { // right child exists only
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL && root->left == NULL)
        { // tow childs exist
            Node *temp = find_predecessor(root);
            root->data = temp->data;
            delete temp;
        }
    }
    else if (root->data > key)
    {
        root->left = deleteInBST(root->left, key);
    }
    else
        root->right = deleteInBST(root->right, key);

    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);

    preorder(root->right);
}

bool searchInBST(Node *root, int x)
{
    // Write your code here.
    Node *temp = root;
    while (temp != NULL)
    {
        if (x == temp->data)
            return true;
        if (x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}
int main()
{

    Node *root = NULL;
    bulid(root);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    deleteInBST(root, 50);
    inorder(root);
    cout << endl;
    return 0;
}