#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<vector<int>>> dp(N + 1,vector<vector<int>>(m + 1,vector<int>(n + 1,0)));
        for(int i = 1;i <= N;++i){
            auto[cnt1,cnt2] = cnt(strs[i - 1]);
            for(int j = 0;j <= m;++j){//一定记住多维可能可以从零开始
                for(int k = 0;k <= n;++k){
                    if(j >= cnt1 && k >= cnt2){
                        dp[i][j][k] = max(dp[i - 1][j][k],1 + dp[i - 1][j - cnt1][k - cnt2]);
                    }
                    else{
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        return dp[N][m][n];
    }
    pair<int,int> cnt(string &s){
        int cnt_0 = 0,cnt_1 = 0;
        for(const char& ch:s){
            if(ch == '0') cnt_0 ++;
            else cnt_1++;
        }
        return make_pair(cnt_0,cnt_1);
    }
};

class Solution2 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string & str: strs) {
            auto [count0, count1] = cnt(str);
            for (int i = m; i >= count0; --i) {
                for (int j = n; j >= count1; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i-count0][j-count1]);
                }
            }
        }
        return dp[m][n];
    }
    pair<int,int> cnt(const string &s){
        int cnt_0 = 0,cnt_1 = 0;
        for(const char& ch:s){
            if(ch == '0') cnt_0 ++;
            else cnt_1++;
        }
        return make_pair(cnt_0,cnt_1);
    }
};