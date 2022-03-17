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
    bool isSymmetric(TreeNode* root) {
        return cmp(root -> left,root ->right);
    }
    bool cmp(TreeNode* a,TreeNode* b){
        
        if(a == nullptr && b == nullptr) return true;
        else if(a == nullptr || b == nullptr) return false;
        else if(a -> val != b -> val) return false;


        if(!cmp(a -> left,b -> right) || !cmp(a -> right,b -> left)){
            return false;
        }
        return true;
    }
};
