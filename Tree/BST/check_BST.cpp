//check_BST_top-down_approach
bool isBST(node* root,int minm=INT_MIN,int maxm=INT_MAX)
{
    if(root==NULL)
        return true;
    
    else if(root->data>=minm && root->data<=maxm && isBST(root->left,minm,root->data) && isBST(root->right,root->data,maxm))
        return true; 
    else
        return false;
}