#include<iostream>
#include<queue>
using namespace std;

class Node 
{   public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

Node* bulid_tree(Node* root)
{   
    int choice;
    cout<<" Press 1 to insert a new node here\n Press 0 to mark it as NULL"<<endl;
    cin>>choice;
    
    
    if(choice== 0)
        return NULL;
    else
    {
        int data;
        cout<<"Entre data to insert"<<endl;
        cin>>data;
        root=new Node(data);  
        cout<<"For the left child of "<<data<<endl;
        root->left=bulid_tree(root->left);
        
        cout<<"For the right child of "<<data<<endl;
        root->right=bulid_tree(root->right);

        return root;
    }
}

Node* create(Node* root)
{
    int data;
    cout<<"ENtre data to insert "<<endl;
    cin>>data;

    if(data== -1)
        return NULL;
    else
    {
        root=new Node(data);
        cout<<"For the left child of "<<data<<endl;
        root->left=create(root->left);
        
        cout<<"For the right child of "<<data<<endl;
        root->right=create(root->right);

        return root;

    }
}

Node* bulit_from_levelorder(Node* root)
{
    queue<Node*> q;
    
    int data;

    cout<<"Entre the root "<<endl;
    cin>>data;

    root= new Node(data);
    q.push(root);

    
    cout<<"Entre -1 to mark the node as NULL"<<endl;
    while(! q.empty())
    {
        Node* temp= q.front();
        q.pop();

        cout<<"Entre the left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1)
        {
            temp->left= new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Entre the right of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1)
        {
            temp->right= new Node(rightdata);
            q.push(temp->right);
        }
    }
    return root;
}
//level order tranversal
void level_order_traversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(! q.empty())
    {
        Node* temp= q.front();
        q.pop();        
        
        if(temp==NULL)
        {
            cout<<endl;

            if(!q.empty())
                q.push(NULL);
        }
        else
        {
        cout<<temp->data<<" ";

        if(temp->left != NULL)
        {       //if left!=null, then pushing in the queue
            q.push(temp->left);
        }

        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
        }
    }
}

void inorder(Node* root)    //LNR:: Left-subtree -> root -> right_subtree
{
    //base case
    if(root==NULL)
        return ;

    inorder(root->left);

    cout<<root->data<<" ";  

    inorder(root->right);

}   

void preorder(Node* root)    // Root -> left-subtree -> right-subtree
{
    //base case
    if(root==NULL)
        return ;

    cout<<root->data<<" ";  

    preorder(root->left);

    preorder(root->right);

}

void postorder(Node* root)    //: root -> Left-subtree -> right_subtree
{
    //base case
    if(root==NULL)
        return ;

    postorder(root->left);

    postorder(root->right);

    cout<<root->data<<" "; 
}

int height(struct Node* node)
{     
    if(node == NULL)
        return 0;
        
    int left=height(node->left);
    int right=height(node->right);
    
    int ans=max(left,right) + 1;
    
    return ans; 
}
int main()
{
    Node* root=NULL;

  //  root = bulid_tree(root);  

   // root=bulit_from_levelorder(root);
   root=create(root);
    cout<<"\n\nLevel order traversal \n"; 
    level_order_traversal(root);

    cout<<"\n Inorder traversal:  ";
    inorder(root);
    cout<<"\n Post order traversal:  ";
    postorder(root);
    cout<<"\n Preorder traversal:  ";
    preorder(root);
    cout<<endl;

    return 0;
}