//building binary tree from given preorder & inorder traversal
node* createTreefromTrav(int *in,int *pre,int s,int e)
{
    static int i=0;
    if(s>e)
        return NULL;
    node *root=new node(pre[i]);//builidng the root node by first element of preorder traversal
    int index=-1;
    for(int j=s;j<=e;j++)
    {
        if(in[j]==pre[i])
        {
            index=j;
            break;
        }
    }
    
    i++;
    
    root->left=createTreefromTrav(in,pre,s,index-1);
    root->right=createTreefromTrav(in,pre,index+1,e);
    
    return root;
}