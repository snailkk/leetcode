class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        if(!(root -> left) && !(root -> right)){
            if(targetSum - root -> val == 0) return true;
            else return false;
        }
        return hasPathSum(root -> left,targetSum - root -> val) || hasPathSum(root -> right,targetSum - root -> val);
    }
};
