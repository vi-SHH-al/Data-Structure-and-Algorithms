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







vector<int> topView(Node *root)
{
    vector<int> ans;

    if(root==NULL)
        return ans;
    //                         second int show the valueof node mapped to the specific vertical colm
    map<int,int> topnode;   // first int represent the vertical column or horizontal distance
   
   queue<pair<Node*,int>>q; //node* represent the nodeand //int == vertical cloumn

    q.push(make_pair(root,0));  //for parent node ,, vc=0

    while( ! q.empty())
    {
        pair<Node*,int> frnt = q.front();
        q.pop();

        Node* frontnode= frnt.first;
        int vc= frnt.second;    //vc of current node
        //if vc is mapped in topnode ,it tell us that it have some previous value 
        // so the current node will hide under the previous node of vc
        //so, we not considered current node.
        if(topnode.find(vc) == topnode.end()) // if vc is not mapped with any node
            topnode[vc] = frontnode->data;      // then mapped it with the current node
        
        if(frontnode->left)
            q.push(make_pair(frontnode->left, vc-1));

        if(frontnode->right)
            q.push(make_pair(frontnode->right, vc+1));
    }
    
    for(auto i:topnode)
        ans.push_back(i.second);
    
    return ans;
}
/*_______________________________________________________________________________________*/

// Bottom view  
/* 
just changed the mapping of vc to its corresponding new node every time
no need to check the condition of top view 
i.e. if a vc is already mapped with a node,then discard the nord,, 
    if not then mapped with the respective vc.
in bottom view we consider the nodes for vc which is occur at last,
so everytime a new node come , replace it with prev node in coreesponding vc

*/

vector<int> topView(Node *root)
{
    vector<int> ans;

    if(root==NULL)
        return ans;
    //                         second int show the valueof node mapped to the specific vertical colm
    map<int,int> topnode;   // first int represent the vertical column or horizontal distance
   
   queue<pair<Node*,int>>q; //node* represent the nodeand //int == vertical cloumn

    q.push(make_pair(root,0));  //for parent node ,, vc=0

    while( ! q.empty())
    {
        pair<Node*,int> frnt = q.front();
        q.pop();

        Node* frontnode= frnt.first;
        int vc= frnt.second;   //vc of current node
       
       // mapped teh data of node with the respective vc
        topnode[vc] = frontnode->data;      
        
        if(frontnode->left)
            q.push(make_pair(frontnode->left, vc-1));

        if(frontnode->right)
            q.push(make_pair(frontnode->right, vc+1));
    }
    
    for(auto i:topnode)
        ans.push_back(i.second);
    
    return ans;
}











/*_______________________________________________________________________________________*/












//  right view of a binary tree
// travese roght ot left
void solve1(Node* root, vector<int>& ans, int level)
{
    if(root==NULL)
        return;
    
    if(level == ans.size())
        ans.push_back(root->data);
    
    
    solve1(root->right, ans, level+1);
    solve1(root->left,ans,level+1);
}

void solve2(Node* root, vector<int>& ans, int level, int& maxlevel)
{
    if(root==NULL)
        return;
    
    if(maxlevel < level)
    {
        ans.push_back(root->data);
        maxlevel = level;
    }
    
    solve2(root->right, ans, level+1,maxlevel);
    solve2(root->left,ans,level+1,maxlevel);
}
vector<int> rightView(Node *root)
{
    vector<int> ans;
    
    solve1(root,ans,0);

    int maxlevel = -1;
    solve2(root,ans,0,maxlevel);

    return ans;
}


// Left side view
// traverse form left ot right subtree
void solve1(Node* root, vector<int>& ans, int level)
{
    if(root==NULL)
        return;
    
    if(level == ans.size())
        ans.push_back(root->data);
    
    solve1(root->left,ans,level+1);
    solve1(root->right, ans, level+1);
    
}


vector<int> leftView(Node *root)
{
    vector<int> ans;
    
    solve1(root,ans,0);

    return ans;
}