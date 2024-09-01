#include<bits/stdc++.h>
using namespace std;

class Node
{   public:
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

class Solution {
  public:
  
  //SOlution -1  O(n2) approach
    int height(Node* node)
    {     
        if(node == NULL)
            return 0;
        
        int left=height(node->left);
        int right=height(node->right);
    
        int ans=max(left,right) + 1;
    
        return ans;
    }
   
    int diameter(Node* root) 
    {
        if(root==NULL)
            return 0;
    
        int ob1 = diameter(root->left);
        int ob2 = diameter(root->right);
        int ob3 = height(root->left) + height(root->right) + 1;
        
        int ans = max( ob1, max( ob2, ob3) );
        
        return ans;
    }


    //Solution 2 -- O(n) approach : returning height along with diameter in recurssion
    //   diameter,height
    pair<int,int> dia(Node* root)
    {
        if(root==NULL)
        {
            pair<int,int> temp=make_pair(0,0);
            return temp;
        }
        
        pair<int,int> left = dia(root->left);
        pair<int,int> right = dia(root->right);
        
        int ob1= left.first;        // diameter of left side
        int ob2= right.first;       //diameter of right side
        
        int ob3= left.second + right.second + 1;        // heightofleft + heightofright + 1
         
        pair<int,int> ans;
        ans.first = max(ob1,max(ob2,ob3));      //calculate diameter
        ans.second = max(left.second , right.second )+1;    // calculate height

        return ans; // return diameter,height
    }
    
};