//building balanced tree from array
node* buildTreefromArray(int arr[],int s,int e)
{
    if(s>e)
        return NULL;
    
    int mid=(s+e)/2;
    node* root=new node(arr[mid]);//first we start creating tree from mid element as root
    
    //then recursive call for left side and right side of the tree 
    root->left=buildTreefromArray(arr,s,mid-1);
    root->right=buildTreefromArray(arr,mid+1,e);
    
    return root;
}