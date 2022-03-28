#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(),n = word2.length();
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        for(int i = 1;i <= m;++i){//注意两个边界条件
            dp[i][0] = i;
        }
        for(int j = 1;j <= n;++j){
            dp[0][j] = j;
        }
        for(int i = 1;i <= m;++i){
            for(int j = 1;j <= n;++j){
                dp[i][j] = min(dp[i - 1][j - 1] + ((word1[i - 1] == word2[j - 1])?0:1),min(dp[i][j - 1] + 1,dp[i - 1][j] + 1));
            }
        }
        return dp[m][n];
    }
};

/*子问题分解：
1. 将word1前i-1,word2前j-1位弄相同：
   a.第i位与第j位本身相同，则需要操作数：dp[i][j] = dp[i - 1][j - 1];
   b.第i位与第j位不相同，则将第i位替换为第j位，所需操作数：dp[i][j] = dp[i - 1][j - 1] + 1;
2. 将前i,j-1位弄相同，第i个后面添加一个和第j个一样的字母。
   则所需操作数：dp[i][j] = dp[i][j - 1] + 1;
3. 将前i-1,j位弄相同，直接删去第i位。
   则所需操作数：dp[i][j] = dp[i - 1][j] + 1;
*/