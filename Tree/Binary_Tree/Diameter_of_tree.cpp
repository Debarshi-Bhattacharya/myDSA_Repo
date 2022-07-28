//diameter of tree(technique1:we count the number of edges in longest path)- O(n^2)
int diameter(node* root)
{
    if(!root)
        return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}

//diameter of tree(technique2:here we count the number of nodes in the longest path)
int dia(node * root, int&res)
{
    if(!root)
        return 0;
    int l=dia(root->left,res);
    int r=dia(root->right,res);
    
    int temp=1+max(l,r);
    int ans=max(temp,1+l+r);
    res=max(res,ans);
    return temp;
}

//finding height and parameter both at a time- O(n)
class Pair{
    public:
        int height;
        int diameter;
};

Pair fastDiameter(node* root)
{
    Pair p;
    if(root==NULL)
    {
        p.height=0;
        p.diameter=0;
        return p;
    }
    Pair left=fastDiameter(root->left);
    Pair right=fastDiameter(root->right);
    
    p.height=max(left.height,right.height)+1;
    p.diameter=max((left.height+right.height),max(left.diameter,right.diameter));
    return p;
}