#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
    
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* insertINBST(node* root,int data)
{
    //base case
    if(root==NULL)
        return new node(data);
    if(data<=root->data)
        root->left=insertINBST(root->left,data);
    else
        root->right=insertINBST(root->right,data);
    
    return root;
}
node* buildtreeBST()
{
//read a list of number till -1,and also insert them into BST
    int d;
    cin>>d;
    node *root=NULL;// atfirst tree is empty
    while(d!=-1)
    {
        root=insertINBST(root,d);
        cin>>d;
    }
    return root;
}