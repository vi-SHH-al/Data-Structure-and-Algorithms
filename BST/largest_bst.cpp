
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
class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
info solve(Node *root, int &ans)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, 1, 0};
    }
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info curr;
    curr.maxi = max(right.maxi, root->data);
    curr.mini = min(left.mini, root->data);
    curr.size = left.size + right.size + 1;

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        curr.isBST = true;
    }
    else
        curr.isBST = false;

    if (curr.isBST)
        ans = max(ans, curr.size);

    return curr;
}
int largestBST(Node *root)
{
    int maxsize = 0;
    info ans = solve(root, maxsize);
    return maxsize;
}
