/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root -> left == nullptr && root -> right == nullptr) return 1;
        int l = 0,r = 0;
        if(root -> left){
            l = minDepth(root -> left);
        }
        if(root -> right){
            r = minDepth(root -> right);
        }
        if(root -> left && root -> right ) return l < r ? l + 1:r + 1;
        else if(root -> left) return l + 1;
        else return r + 1;
    }
};
