#include <bits/stdc++.h>
using namespace std;
/*
    1.  Validate BST
    2.   LCA in BST
    3.   Two Sum IV - Input is a BST
    4.   BST to Linked List
    5.   BST to balanced BST
    6.   BST from preorder
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*_______________________________________________________________________________________________*/

/*
    Validate BST

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
class Solution
{
public:
    bool solve(TreeNode *root, long min, long max)
    {
        if (root == NULL)
            return true;

        if (min < root->val && max > root->val)
        {

            bool left = solve(root->left, min, root->val);
            bool right = solve(root->right, root->val, max);

            return left && right;
        }
        return false;
    }

    bool isValidBST(TreeNode *root)
    {

        return solve(root, LONG_MIN, LONG_MAX);
    }
};

/*______________________________________________________________________________________________*/

/*
        LCA in BST
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T
that has both p and q as descendants (where we allow a node to be a descendant of itself).”


*/

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;

        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        return root;
    }
};

/*_________________________________________________________________________________________________________________*/

/*

. Two Sum IV - Input is a BST


    Given the root of a binary search tree and an integer k,
    return true if there exist two elements in the BST such that their sum is equal to k,
    or false otherwise.
*/

class Solution
{
public:
    void inorder(vector<int> &in, TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(in, root->left);
        in.push_back(root->val);
        inorder(in, root->right);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> arr;
        inorder(arr, root);

        int i = 0;
        int j = arr.size() - 1;

        while (i < j)
        {
            if (arr[i] + arr[j] == k)
                return true;

            if (arr[i] + arr[j] > k)
                j--;
            else
                i++;
        }
        return false;
    }
};

/*_______________________________________________________________________________________________________________________*/

/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where
the right child pointer points to the next node in the list
and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

class Solution
{
public:
    void preorder(vector<TreeNode *> &nodes, TreeNode *root)
    {
        if (root == NULL)
            return;

        nodes.push_back(root);

        preorder(nodes, root->left);

        preorder(nodes, root->right);
    }
    void flatten(TreeNode *root)
    {

        if (root == NULL || root->left == NULL && root->right == NULL)
            return;

        vector<TreeNode *> nodes;
        preorder(nodes, root);
        int n = nodes.size();

        TreeNode *first = nodes[0];

        TreeNode *curr = first;

        for (int i = 1; i < n; i++)
        {
            TreeNode *temp = nodes[i];

            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }

        curr->right = NULL;
        curr->left = NULL;

        root = first;
    }
};

/*___________________________________________________________________________________________________________________*/

/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values.
If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
*/

class Solution
{
public:
    void inorder(vector<int> &in, TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(in, root->left);
        in.push_back(root->val);
        inorder(in, root->right);
    }

    TreeNode *in_to_BST(vector<int> &in, int s, int e)
    {
        if (s > e)
            return NULL;

        int mid = (s + e) / 2;

        TreeNode *root = new TreeNode(in[mid]);
        root->left = in_to_BST(in, s, mid - 1);
        root->right = in_to_BST(in, mid + 1, e);

        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> inorder_val;
        inorder(inorder_val, root);
        int n = inorder_val.size() - 1;
        return in_to_BST(inorder_val, 0, n);
    }
};

/*____________________________________________________________________________________________________________________*/

/*
Given an array of integers preorder,
which represents the preorder traversal of a BST (i.e., binary search tree),
construct the tree and return its root.

It is guaranteed that there is always possible to
find a binary search tree with the given requirements for the given test cases.
*/

class Solution
{
public:
    TreeNode *solve(vector<int> &preorder, int mini, int maxi, int &i)
    {

        if (i >= preorder.size())
            return NULL;

        if (preorder[i] < mini || preorder[i] > maxi)
            return NULL;

        TreeNode *root = new TreeNode(preorder[i++]);

        root->left = solve(preorder, mini, root->val, i);
        root->right = solve(preorder, root->val, maxi, i);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return solve(preorder, INT_MIN, INT_MAX, i);
    }
};