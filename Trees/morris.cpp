
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

/*    Inorder Traversal  through MOrris traversal  */
Node* findpre(Node* temp)
{   
    Node* root = temp;
    root = root->left;

    while(root->right != NULL && root->right != temp)
    {
        root=root->right;
    }
    return root;
}

vector<int> inorderTraversal(Node* root) {
    
    vector<int> inorder;

    if(root==NULL)
    return inorder;
    
    Node* curr=root;

    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            inorder.push_back(curr->val);
            curr=curr->right;
        }
        else
        {
            Node* pred = findpre(curr);

            if(pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}


vector<int> preorderTraversal(Node* root) {
    
    vector<int> preorder;

    if(root==NULL)
    return preorder;
    
    Node* curr=root;

    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            preorder.push_back(curr->val);
            curr=curr->right;
        }
        else
        {
            Node* pred = findpre(curr);

            if(pred->right == NULL)
            {   
                preorder.push_back(curr->val);
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}


Node* find_post(Node* root){
    Node* curr = root->right;

    while(curr->left != NULL && curr->left != root){
        curr= curr->left;
    }
    return root;
}

vector<int> postorderTraversal(Node* root){
    vector<int> postorder;

    Node* curr = root;

    while(curr != NULL){
        if(curr->right == NULL)
        {
         postorder.push_back(curr->val);   
         curr = curr->left;
        }
        else
        {
            Node* pred = find_post(curr);

            if(pred -> left == NULL)
            {   
                postorder.push_back(curr->val);
                pred->left = curr;
                curr = curr->left;
            }
            else
            {
                pred ->right = NULL;
                curr = curr->left;
            }
        }
    }
    reverse(postorder.begin() , postorder.end());
    return postorder;
}


/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same Node class where the right child pointer points to the next node in the list 
    and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

void flatten(Node *root)
{
    Node* curr = root;
    
    while(curr != NULL)
    {
        if(curr->left)
        {
            Node* prev = curr->left;

            while(prev->right)
                prev= prev->right;
                
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr= curr->right;
    }
}