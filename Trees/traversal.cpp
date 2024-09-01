/*
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.
*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector <int> zigZagTraversal(Node* root)
{
    vector<int> result;
    
    queue<Node*> q;
    q.push(root);
    
    bool lefttoright = true;
    
    while(! q.empty())
    {
        int size=q.size();
        vector<int> ans(size);
        
        for(int i=0;i<size;i++)
        {
            Node* frnt = q.front();
            q.pop();
            
            int index = lefttoright ? i: size-1-i;
            ans[index] = frnt->data;
            
            if(frnt->left)
                q.push(frnt->left);
            
            if(frnt->right)
                q.push(frnt->right);
            
        }
        lefttoright = !lefttoright;
        
        for(auto i:ans)
            result.push_back(i); 

    }
    return result;
}
/*-----------------------------------------------------------------------------------------------*/
//   Boundar Traversal:
    
void lefttraverse(Node* root , vector<int> &ans)
{
    if(root==NULL)
        return;
    if(root->left == NULL && root->right == NULL)
        return ;    //leaf  case;
    
    ans.push_back(root->data);
    
    if(root->left)
        lefttraverse(root->left,ans);
    else
        lefttraverse(root->right,ans);
        
}

void leaf(Node* root,vector<int>& ans)  
{
    if(root==NULL)
    return ;
    if(root ->left ==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    
    leaf(root->left,ans);
    leaf(root->right,ans);
}

void righttraverse(Node* root, vector<int>& ans)
{
    if(root==NULL)
        return;
    if(root->left == NULL && root->right == NULL)
        return ;    //leaf  case;
        
    if(root->right)
        righttraverse(root->right,ans);
    else
        righttraverse(root->left,ans);
    ans.push_back(root->data);
}

vector <int> boundary(Node *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
        
    ans.push_back(root->data);
    lefttraverse(root->left,ans);
    
    leaf(root->left,ans);
    leaf(root->right,ans);
    
    righttraverse(root->right,ans);
    
    return ans;
}

/*_________________________________________________________________________________________________*/

// Vertical order traversal
vector<int> verticalOrder(Node *root)
{
    map < int, map < int, vector < int > > > nodes;
    queue < pair < Node* , pair < int, int > > > q;
    
    q.push(make_pair(root,make_pair(0,0)));
    
    while( ! q.empty())
    {
        pair<Node*,pair<int,int>> temp = q.front();
        q.pop();
        
        Node* frontnode = temp.first;
        int vc = temp.second.first;
        int lvl = temp.second.second;
        
        nodes[vc][lvl].push_back(frontnode->data);
        
        if(frontnode->left)
            q.push(make_pair(frontnode->left,make_pair(vc-1,lvl+1)));
        if(frontnode->right)
            q.push(make_pair(frontnode->right,make_pair(vc+1,lvl+1)));
            
    }
    vector<int> ans;
    for(auto i: nodes)
        for(auto j:i.second)
            for(auto k:j.second)
                ans.push_back(k);
    
    return ans;
}


//Diagonal Traversal
vector<int> diagonal(Node *root)
{
     vector<int> ans;
    if(root == NULL) return ans;

    queue<Node*> q;

    q.push(root);

    // Give priority to left part first
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        while(temp != NULL){
            ans.push_back(temp->data);

            if(temp->left != NULL){
                q.push(temp->left);
            }

            temp = temp->right;
        }
    }

    return ans;
}
