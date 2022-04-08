#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(candidates,ans,tmp,0,target);
        int n = candidates.size();
        return ans;
    }
    void dfs(vector<int> & candidates,vector<vector<int>> &ans,vector<int>&tmp,int l,int target){
        int n = candidates.size();
        if(l >= n) return;
        if(candidates[l] > target) return;
        for(int i = l;i < n;){
            if(candidates[i] == target){
                tmp.push_back(candidates[i]);
                ans.push_back(tmp);
                tmp.pop_back();
                break;
            }
            else{
                tmp.push_back(candidates[i]);
                dfs(candidates,ans,tmp,i + 1,target - candidates[i]);
                tmp.pop_back();
                int num = candidates[i];
                while(i < n && candidates[i] == num){
                    ++i;
                }
            }
        }
    }
};
int main(){
    Solution s;
    vector<int> candidates = {1};
    vector<vector<int>> ans = s.combinationSum2(candidates,2);
}