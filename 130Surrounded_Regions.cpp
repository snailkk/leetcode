#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dir =  {-1,0,1,0,-1};//上、右、下、左四个方向
    void solve(vector<vector<char>>& board) {
        int m = board.size(),n = board[0].size();
        if(m == 1 || n == 1) return;
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    if(board[i][j] == 'O'){
                        dfs(board,{i,j},1);
                    }
                }
            }
        }
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(board[i][j] == 'O'){
                    dfs(board,{i,j},0);
                }
            }
        }
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(board[i][j] == 'P'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>> &board,pair<int,int> start,int flag){
        int x = start.first,y = start.second;
        int m = board.size(),n = board[0].size();
        if(flag == 0) board[x][y] = 'X';
        else if(flag == 1) board[x][y] = 'P';
        for(int i = 0;i < 4;++i){
            int p = x + dir[i],q = y + dir[i + 1];
            if(p >= 0 && p < m && q >= 0 && q < n){
                if(board[p][q] == 'O')
                dfs(board,{p,q},flag);
            }
        }
    }
};
int main(){
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution s;
    s.solve(board);
}