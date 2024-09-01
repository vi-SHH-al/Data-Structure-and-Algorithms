#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

/*   tree from  INorder and PREorder*/

int pos(int in[], int start, int end, int key)
{
    for (int i = start; i <= end; i++)
        if (in[i] == key)
            return i;
    return -1;
}

Node *solve(int in[], int pre[], int &index, int instart, int inend, int n)
{
    if (instart > inend || index >= n) // base conditon
        return NULL;

    int element = pre[index++]; // taken root from preorder

    int position = pos(in, instart, inend, element); // findinf posstion of root in inorder

    Node *root = new Node(element); // creating root

    root->left = solve(in, pre, index, instart, position - 1, n); // calling of sub-tree , left part of inorder
    root->right = solve(in, pre, index, position + 1, inend, n);  // calling , right part of inorder

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int preorderIndex = 0;

    Node *ans = solve(in, pre, preorderIndex, 0, n - 1, n);
    return ans;
}

/*  ___________________________________________________________________________________________________________________*/

/*   tree from  INorder and POSTorder*/

int pos(int in[], int start, int end, int key)
{
    for (int i = start; i <= end; i++)
        if (in[i] == key)
            return i;
    return -1;
}

Node *solve(int in[], int post[], int &index, int instart, int inend, int n)
{
    if (instart > inend || index >= n) // base conditon
        return NULL;

    int element = post[index--];                     // taken root from postorder
                                                     // decrement for the next root
    int position = pos(in, instart, inend, element); // findinf posstion of root in inorder

    Node *root = new Node(element); // creating root

    // right part will call first because of postorder ( left-right-root)  on decerementing we get the right part of tree
    root->right = solve(in, post, index, position + 1, inend, n);  // calling , right part of inorder
    root->left = solve(in, post, index, instart, position - 1, n); // calling of sub-tree , left part of inorder
    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    int postorderIndex = n - 1;

    Node *ans = solve(in, post, postorderIndex, 0, n - 1, n);
    return ans;
}