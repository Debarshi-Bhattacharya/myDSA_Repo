int count(node* root)
{
    if(root==NULL)
        return 0;
    else
        return 1+count(root->left)+count(root->right);
}

int nodesum(node* root)
{
    if(root==NULL)
        return 0;
    else
        return root->data+nodesum(root->left)+nodesum(root->right);
}