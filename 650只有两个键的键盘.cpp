#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        vector<int> dp(n + 1,0);
        for(int i = 1;i <= n;++i){
            int min = i;
            for(int j = 1;j <= (i / 2);++j){//边界条件一定要想清楚
                if(i%j == 0){//刚好整个能复制，然后整个复制，再重复粘贴i/j次。
                    min = (dp[j] + (i/j)) < min?dp[j] + (i/j):min;//取这些操作中最小的那一个
                }
            }
            dp[i] = min;
        }
        return dp[n];
    }
};

//别人的解：更快一点
//利用等价性

/*
对于每个位置j，如果 j 可以被 i 整除，那么长度 i 就可以由长度 j 操作得到，其操作次数等价于把一个长度为 1
的 A 延展到长度为 i/j。因此我们可以得到递推公式 dp[i] = dp[j] + dp[i/j]。
*/
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        int h = sqrt(n);
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            for (int j = 2; j <= h; ++j) {
                if (i % j == 0) {
                    dp[i] = dp[j] + dp[i/j];
                    break;
                }
            }
        }
        return dp[n];
    }
};