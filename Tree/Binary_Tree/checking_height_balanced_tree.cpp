//checking height balanced tree
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return diffHeight(root)!=-1;
    }
    int diffHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        int leftheight=diffHeight(root->left);
        if(leftheight==-1)
            return -1;//height of a node becoming '-1', means it is not balanced hence whole tree isn't too
        int rightheight=diffHeight(root->right);
        if(rightheight==-1)
            return -1;
        if(abs(leftheight-rightheight)>1)//at any node if the difference is greater than 1 then it will pass '-1' to its parent node
            return -1;
        return 1+max(leftheight,rightheight);
        
    }
};