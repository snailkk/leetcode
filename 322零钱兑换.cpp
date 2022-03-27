#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1,vector<int>(amount + 1,amount + 2));//注意初始值选取
        for(int i = 1;i <= n;++i){//边界条件赋值
            dp[i][0] = 0;
        }
        for(int i = 1;i <= n;++i){
            int w = coins[i - 1];
            for(int j = 1;j <= amount;++j){
                if(j >= w){
                    dp[i][j] = min(dp[i - 1][j],dp[i][j - w] + 1);
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][amount] == amount + 2?-1:dp[n][amount];
    }
};