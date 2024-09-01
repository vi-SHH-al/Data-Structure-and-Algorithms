
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};


/*
    Sum of Longest BloodLine
    LCA of Binary Tree
    K-sum paths
    Kth Ancestor
    max sum of adajcent nodes
*/

/*___________________________________________________________________________________________________*/
// Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(),
// that find the sum of all nodes on the longest path from root to leaf node.
// If two or more paths compete for the longest path, 
//then the path having maximum sum of nodes is being considered.

void solve(Node* root, int len,int sum,int& maxlen,int& maxsum)
{
    if(root==NULL)
    {
        if(len > maxlen)
        {
            maxsum=sum;
            maxlen=len;
        }
        else if(len==maxlen)
        {
            maxsum=max(sum,maxsum);
        }
        return;
    }

    sum=sum+root->data;
    
    solve(root->left,len+1,sum,maxlen,maxsum);
    solve(root->right,len+1,sum,maxlen,maxsum);

}


int sumOfLongRootToLeafPath(Node *root)
{ 
    int maxsum=INT_MIN;
    int maxlen=0;
    solve(root,0,0,maxlen,maxsum);
    return maxsum;
}

/*_________________________________________________________________________________________________________*/
// Given a Binary Tree with all unique values and two nodes value, n1 and n2. 
// The task is to find the lowest common ancestor of the given two nodes. 
// We may assume that either both n1 and n2 are present in the tree or none of them are present.

// LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

// Find the ans in left subtree and then right subtree and if both subtree give us the !NULL
// i.e. they have found the key roots, so return the current root which have both ans !NULL
Node* lca(Node* root ,int n1 ,int n2 )
{
    if(root==NULL)
        return root;
    if(root->data==n1 || root->data==n2)
        return root;        //data is found and return the root to its parent

    Node* leftans=lca(root->left, n1, n2);
    Node* rightans=lca(root->right, n1, n2);
        
    if(leftans != NULL && rightans != NULL)
        return root;
    else 
        if(leftans != NULL && rightans==NULL )
            return leftans;
        else 
            if(leftans ==NULL & rightans!=NULL)
                return rightans;
            else
                return NULL;   
    
}

/*_________________________________________________________________________________________________*/


// Given a binary tree and an integer K.
// Find the number of paths in the tree which have their sum equal to K.
// A path may start from any node and end at any node in the downward direction.

// storing the nodes data in vectori.e. path and checking does the path sum =K 
//     if yes then increase the count
// then popping the pushed node,
// here we checking from bottom to top for the sum ( for from i=size to 0 )
// calling the function for left and then right


void solve(Node* root, int k , int& count,vector<int>& path)
{
    if(root == NULL)
        return ;
    
    path.push_back(root->data);
    
    solve(root->left,k,count,path);
    solve(root->right,k,count,path);

    int size=path.size();
    int sum=0;
    for(int i=size-1; i>=0;i--)
    {   
        sum+=path[i];
        if(sum==k)
            count++;
    }
    path.pop_back();

}
int sumK(Node *root,int k)
{
    int count=0;
    vector<int> path;
    solve(root,k,count,path);
    return count;
}



/*_______________________________________________________________________________________________________*/
// Kth ancestor  

// Given a binary tree of size  N, a node, and a positive integer k.,
// Your task is to complete the function kthAncestor(), 
// the function should return the kth ancestor of the given node in the binary tree. 
// If there does not exist any such ancestor then return -1.
// Note: It is guaranteed that the node exists in the tree.


Node* solve(Node* root, int &k, int node) 
{
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == node) 
    {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);


    //wapas
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    

}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

/*______________________________________________________________________________________________*/

// Given a binary tree with a value associated with each node, 
// we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint 
// that no two chosen node in subset should be directly connected that is, 
// if we have taken a node in our sum 
// then we can’t take its any children or parents in consideration and vice versa.

                                               

//first element - max sum including the root
//second element - max sum excluding the root
pair<int,int> solve(Node* root)
{
    if(root==NULL)
    {
        return make_pair(0,0);
    }
    
    pair<int,int> leftans= solve(root->left);
    pair<int,int> rightans=solve(root->right);
    
    pair<int,int> ans;
    ans.first = leftans.second + rightans.second + root->data;
    ans.second = max(leftans.first, leftans.second) + max(rightans.first,rightans.second);
    //second of ans may include the child node or exclude 
    // decide which give us the max sum by excluding the child or by including
    
    return ans;
}


int getMaxSum(Node *root) 
{
    
    pair<int,int> ans=solve(root);
    
    return max(ans.first,ans.second);
}