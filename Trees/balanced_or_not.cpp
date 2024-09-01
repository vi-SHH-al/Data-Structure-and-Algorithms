#include<bits/stdc++.h>
using namespace std;

struct Node
{   
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution{
    public:
   
    pair<bool,int> bal(Node* root)
    {
        if(root==NULL)
        {
            pair<bool,int> p = make_pair(1,0);
            return p;
        }
        
        pair<bool,int> left = bal(root->left);
        pair<bool,int> right = bal(root->right);
        
        bool leftans  = left.first;
        bool rightans = right.first;
        
        bool diff= abs(left.second - right.second ) <= 1;
        
        pair<bool,int> ans;
        ans.second =  max(left.second, right.second) +1;

        if(leftans && rightans && diff)
            ans.first = true;
        else
            ans.first = false;
            
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
       return bal(root).first;
    }
};