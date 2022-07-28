//replacing each node with the sum of its child nodes
//the key point here is: we are updating a node with the sum of its child node but when we will transfer the
//value to its parent node we have to send the sum of child nodes and the node itself so before sending we
//have to store the node value to a temporary node
int sumReplacement(node* root)
{
    if(root==NULL)
        return 0;
        
    if(root->left==NULL && root->right==NULL)//when we reached a leaf node it will be replaced wit its own value
        return root->data;
        
    int temp=root->data;//storing value of current node in a temp variable
    root->data=sumReplacement(root->left)+sumReplacement(root->right);
    
    return temp+root->data;
}