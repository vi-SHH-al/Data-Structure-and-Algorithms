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

/*
Approach 1::

1. Find the inorder of two given BST
2. merge 2 sorted array( i.e. two inorder vecotors)
3. create a BST from the obtained sorted array i.e. inorder for final BST

TC : O(m+n)
Sc : O(m+n)
*/

void inorder(Node *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArray(vector<int> a, vector<int> b)
{
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = b[j++];
        }
    }
    while (i < a.size())
    {
        ans[k++] = a[i++];
    }
    while (j < b.size())
        ans[k++] = b[j++];

    return ans;
}
Node *inToBst(int s, int e, vector<int> &in)
{
    if (s > e)
        return NULL;
    int mid = (s + e) / 2;
    Node *root = new Node(in[mid]);
    root->left = inToBst(s, mid - 1, in);
    root->right = inToBst(mid + 1, e, in);

    return root;
}
Node *mergeBST(Node *root1, Node *root2)
{
    // Write your code here.
    vector<int> bst1, bst2;

    inorder(root1, bst1);
    inorder(root2, bst2);

    vector<int> mergebst = mergeArray(bst1, bst2);

    return inToBst(0, mergebst.size() - 1, mergebst);
}

/*
    Approach 2



*/