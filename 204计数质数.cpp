#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        int cnt = n - 2;
        vector<bool> prime(n,true);
        for(int i = 2;i < n;++i){
            if(prime[i]){
                for(int j = 2 * i;j < n;j += i){
                    if(prime[j]){
                        prime[j] = false;
                        --cnt;
                    }
                }
            }
        }
        return cnt;
    }
};