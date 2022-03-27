#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int> weights,vector<int> values,int N,int W){
    vector<vector<int>> dp(N + 1,vector<int>(W + 1,0));
    for(int i = 1;i <= N;++i){
        int w = weights[i-1],v = values[i-1];
        for(int j = 1;j <= w;++j){
            if(j >= w){
                dp[i][j] = max(dp[i-1][j],dp[i][j-w] + v);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}


//带空间压缩
int knapsack(vector<int> weights,vector<int> values,int N,int W){
    vector<int> dp(W + 1,0);
    for(int i = 1;i <= N;++i){
        int w = weights[i - 1],v = values[i - 1];
        for(int j = w;j <= W;++j){
            dp[j] = max(dp[j],dp[j - w] + v);
        }
    }
}