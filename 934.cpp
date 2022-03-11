#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
class Solution{
	public:
	vector<int> dir = {-1,0,1,0,-1};
	void dfs(queue<pair<int,int>> &q,int i,int j,vector<vector<int>> &grid){
		grid[i][j] = 2;
		for(int d = 0;d < 4;d++){
			int x = i + dir[d];
			int y = j + dir[d + 1];
			if(x >= 0 && x < (int)grid.size() && y >= 0 && y < grid[0].size()){
				if(grid[x][y] == 1){
					dfs(q,x,y,grid);
				}
				else{
					q.push({x,y});
				}
			}
		}
	}
	int shortestBridge(vector<vector<int>>& grid){
		int m = grid.size();
		int n = grid[0].size();
		queue<pair<int,int>> q;
		int flag = 0;
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				if(grid[i][j] == 1){
					dfs(q,i,j,grid);
					flag = 1;
					break;
				}
			}
			if(flag == 1){
				break;
			}
		}
		int ret = 0;
		while(!q.empty()){
			ret++;
			int size_q = q.size();
			while(size_q--){
				auto[i,j] = q.front();
				q.pop();
				for(int k = 0;k < 4;k++){
					int x = i + dir[k];
					int y = j + dir[k + 1];
					if(x >= 0 && x < m && y >= 0 && y < n){
						if(grid[x][y] == 1){
							return ret;
						}
						else if(grid[x][y] == 0){
							q.push({x,y});
						}
						grid[x][y] = 2;
					}
				}
			}
		}
		return 0;
	}
};

int main(){
}
