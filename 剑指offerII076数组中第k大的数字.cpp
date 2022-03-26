#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return ser(nums,k,0,nums.size() - 1);
    }
    int ser(vector<int>& nums,int k,int l,int r){
    
        int key = nums[l];
        int f = l + 1,s = r;
        while(f <= s){
            while(f <= s && nums[f] <= key){
                f++;
            }
            while(f <= s && nums[s] >= key){
                s--;
            }
            if(f > s)break;
            swap(nums[f],nums[s]);
        }
        nums[l] = nums[s];
        nums[s] = key;
        if(s == nums.size() - k) return nums[s];
        if(s < nums.size() - k) return ser(nums,k,s + 1,r);
        if(s > nums.size() - k) return ser(nums,k,l, s - 1);
        return 0;
    }
};