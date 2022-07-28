node* deleteBST(node* root,int data)
{
    if(root==NULL)
        return NULL;
    else if(data<root->data)
    {
        root->left= deleteBST(root->left,data);
        return root;
    }
    else if(root->data==data)
    {
        //case1: 0 children
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        //case2: 1 child(left or right)
        if(root->left!=NULL && root->right==NULL)
        {
            node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL)
        {
            node* temp=root->right;
            delete root;
            return temp;
        }
        //case 3: 2children
        if(root->left!=NULL && root->right!=NULL)
        {
            //finding inorder successor of root, which will be the minimum element of right subtree of the root
            node * replace=root->right;
            while(replace->left!=NULL)
            {
                replace=replace->left;
            }
            root->data=replace->data;//replace the node value with its inorder successor 
            
            root->right=deleteBST(root->right,replace->data);//now we have to delete the node of the inorder successor , 
            //as it may give case1 and case 2 condition we call the same deleteBST function for the right subtree of the root with replace->data to be deleted
        }    
        return root;
    }
    else
    {
        root->right=deleteBST(root->right,data);
        return root;
    }
}