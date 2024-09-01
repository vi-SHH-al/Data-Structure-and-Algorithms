

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left=NULL;
        right=NULL;
    }
};

Node* create(Node* root,map<Node*,Node*>& ntp,int target)
  {
      if(root==NULL)
        return NULL;
        
        
     Node* res=NULL;
    queue<Node*> q;
    
    q.push(root);
    ntp[root] == NULL;
    
    while(!q.empty())
    {
        Node* front=q.front();
        q.pop();
        
        if(front->data == target)
            res = front;
            
        if(front->left)
        {
            ntp[front->left]= front;
            q.push(front->left);
        }
         if(front->right)
        {
            ntp[front->right]= front;
            q.push(front->right);
        }
  
    }
          return res;
  }
  
  
int burn(Node* root, map<Node*,Node*> ntp)
  {
      map<Node*,bool> visited;
      queue<Node*> q;
      
      q.push(root);
      visited[root]=true;
      
      int ans=0;
      while(! q.empty())
      {
          bool flag=0;
          int size= q.size();
          for(int i=0;i<size;i++)
          {
              Node* front= q.front();
              q.pop();
              
              if(front->left && !visited[front->left])
              {     
                  flag=1;
                  q.push(front->left);
                  visited[front->left]=1;
               }
               
                if(front->right && !visited[front->right])
              {     
                  flag=1;
                  q.push(front->right);
                  visited[front->right]=1;
               }
                if(ntp[front] && !visited[ntp[front]])
              {     
                  flag=1;
                  q.push(ntp[front]);
                  visited[ntp[front]]=1;
               }
               
              
            }
          if(flag)
                ans++;
      }
       return ans;
  }
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> ntp;
        Node* target_node= create(root,ntp,target);
        
        int ans=burn(target_node,ntp);
        
        return ans;
    }