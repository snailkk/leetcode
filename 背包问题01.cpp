#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int> weights,vector<int> values,int N ,int W){
    vector<vector<int>> dp(N + 1,vector<int>(W + 1,0));
    for(int i = 1;i < dp.size();i++){
        int w = weights[i],v = values[i];
        for(int j = 1;j < dp[i].size();j++){
            if(j >= w){
                dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - w] + v);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][W];
}

//带空间压缩
int knapsack(vector<int> weights,vector<int> values,int N,int W){
    vector<int> dp(W + 1,0);
    for(int i = 1;i < N;++i){
        int w = weights[i],v = values[i];
        for(int j = W; j >= w; --j){
            dp[j] = max(dp[j],dp[j-w] + v);
        }
    }
    return dp[W];
}