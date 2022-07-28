
//  Following is the Binary Tree node structure:
    
template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

bool isLeaf(TreeNode<int>* root)
{
    return !root->left && !root->right;
}
void addLeftBoundary(TreeNode<int>* root,vector<int>&res)
{
    //Left excluding Leaf Nodes
    //will go left, if not leaf add into the dataStructure
    //if left is not present then go right
	TreeNode<int>* curr=root->left;
    while(curr)
    {
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}
void addLeaves(TreeNode<int>* root,vector<int>&res)
{
    // the leaf nodes are in the boundary like they are in the inorder traversal<root,left,right>
	if(isLeaf(root)) res.push_back(root->data);                        
    /*       1
           /   \
          2     3
        /  \   / \             Leaves are 4 5 6 7; are in inorder 
       4    5 6   7
    */                                             
    if(root->left) addLeaves(root->left,res);         
    if(root->right) addLeaves(root->right,res);
}
void addRightBoundary(TreeNode<int>* root,vector<int>&res)
{
    //Right excluding Leaf Nodes
    //will go right, if not leaf add into the dataStructure
    //if right is not present then go left
	TreeNode<int>* curr=root->right;
    stack<int>s;
    while(curr)
    {
        if(!isLeaf(curr)) s.push(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    while(!s.empty())//as it will be come revese so stored in a stack then moved to the datastructure
    {
        res.push_back(s.top());
        s.pop();
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>res;
    if(!root) return res;   
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root,res);
    addLeaves(root,res);   
    addRightBoundary(root,res);
    return res;
}
