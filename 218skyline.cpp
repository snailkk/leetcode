#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int,int>> max_heap;
        vector<vector<int>> ret;
        int i = 0,len = buildings.size();
        int x = 0,h = 0;
        while(i < len || !max_heap.empty()){//可以先忽略这里的!max_heap.empty()，先得出不完整的答案
            if(max_heap.empty() || (i < len && buildings[i][0] <= max_heap.top().second)){//可以先忽略这里的max_heap.empty() || (i < len
                x = buildings[i][0];
                while(i < len && x == buildings[i][0]){//当发现一个比最高的建筑物右端小的，就疯狂往里面装左端相同的
                    max_heap.push({buildings[i][2],buildings[i][1]});//最后如果拔高了天际线，就将它的左端和它的高度（此时是最高的高度）装入
                    ++i;                                             //发现最高的高度还是上一个装入的高度那就不装
                }
            }
            else{
                x = max_heap.top().second;//比最高的建筑物大或者后面没有建筑物来了，那就先记下此时最高建筑物的右端，因为此时最高建筑物右端
                while(!max_heap.empty() && x >= max_heap.top().second){//一定能形成一个天际点
                    max_heap.pop();//把比较高的建筑物去掉，此时将是之前比较高的建筑物的右端点，和现在比较高的建筑物的高度匹配
                }
            }
            h = (max_heap.empty())? 0 : max_heap.top().first;//高度取此时最高建筑物高度
            if(ret.empty() || h != ret.back()[1]){//ret.back()[1] 是之前最高建筑物右端，如果这次还取这个值，说明没拔高天际线，不加入
                ret.push_back({x,h});
            }
        }
        return ret;
    }
};