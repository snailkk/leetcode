#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int W = sum / 2, n = nums.size();
        vector<int> dp(W + 1,0);
        for(int i = 1;i <= n;++i){
            int w = nums[i - 1];//带空间压缩写法，体积和价值一样大，希望使包里面装的东西的体积和自己的背包一样大
            for(int j = W;j >= w;--j){
                dp[j] = max(dp[j],dp[j - w] + w);
            }
        }
        if(dp[W] == W) return true;
        else return false;
    }
};