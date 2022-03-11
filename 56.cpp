class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> pre(intervals[0]);
        vector<vector<int>> ans;
        for(int i = 1;i < intervals.size();i++){
            if(intervals[i][0] <= pre[1]){
                if(intervals[i][1] <= pre[1]){
                    continue;
                }
                pre[1] = intervals[i][1];
            }
            else{
                ans.push_back(pre);
                pre[0] = intervals[i][0];
                pre[1] = intervals[i][1];
            }
        }
        ans.push_back(pre);
        return ans;
    }
};
