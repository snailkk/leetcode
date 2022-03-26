#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),max_index = 0;
        for(int i = 0;i < n;++i){
            if(i > max_index) return false;
            max_index = max(max_index,i + nums[i]);
            if(max_index >= n - 1) return true;
        }
        return false;
    }
};