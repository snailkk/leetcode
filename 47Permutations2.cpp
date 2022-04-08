#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
        unordered_map<int,int> ma;//实际上这种做法虽然好理解，但是比较拉跨，但是标准答案的解法实在看不懂
        for(int i = l;i < n;++i){
            if(ma.find(tmp[i]) == ma.end()){
                ma[tmp[i]] = 1;
                swap(tmp[l],tmp[i]);
                backtrack(ans,tmp,l + 1);
                swap(tmp[l],tmp[i]);
            }
            else{
                continue;
            }
        }
    }
};