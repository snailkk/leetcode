#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret = {""};
        dfs(root,0,ret);
        return ret;
    }
    void dfs(TreeNode* root,int i,vector<string>& ret){
        ret[i] += to_string(root -> val);
        if(!(root -> left == nullptr && root -> right == nullptr))
            ret[i] += "->";
        if(root -> left != nullptr && root -> right != nullptr){
            ret.push_back(ret[i]);
            dfs(root -> right,ret.size() - 1,ret);
            dfs(root -> left,i,ret);
        }
        else if(root -> left != nullptr){
            dfs(root -> left,i,ret);
        }
        else if(root -> right != nullptr){
            dfs(root -> right,i,ret);
        }
    }
};