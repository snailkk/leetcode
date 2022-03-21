#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> merge_sort(vector<int> &nums,int l,int r){
    if(l == r) return vector<int>{nums[l]};
    else if(l > r) return vector<int>{};
    int m = (l + r) / 2;
    vector<int> l_n = merge_sort(nums,l,m);
    vector<int> r_n = merge_sort(nums,m + 1,r);
    vector<int> ret = {};
    int i = 0,j = 0;
    while(i < l_n.size() || j < r_n.size()){
        if(j >= r_n.size() || (i < l_n.size() && l_n[i] < r_n[j])){
            ret.push_back(l_n[i]);
            i++;
        }
        else{
            ret.push_back(r_n[j]);
            j++;
        }
    }
    return ret;
}
bool compare(const int & a,const int & b){
    return a > b;
}
int main(){
    vector<int> nums = {2,1,4,0,0,0,3,5,6,9,7,8};
    // vector<int> ret = merge_sort(nums,0,nums.size() - 1);
    sort(nums.begin(),nums.end(),compare);
    for(const int &n:nums){
        cout << n << ' ';
    }
    cout << endl;
}