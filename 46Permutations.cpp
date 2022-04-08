#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans,nums,0);
        return ans;
    }
    void backtrack(vector<vector<int>>& ans,vector<int> &tmp,int l){
        int n = tmp.size();
        if(l >= n - 1){
            ans.push_back(tmp);
            return;
        }
        for(int i = l;i < n;++i){
            swap(tmp[l],tmp[i]);
            backtrack(ans,tmp,l + 1);
            swap(tmp[l],tmp[i]);
        }
    }
};