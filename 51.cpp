#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
	public:
		vector<vector<string>> solveNQueens(int n){
			vector<bool> column(n,true);
			vector<bool> ldiag(2 * n - 1,true);
			vector<bool> rdiag(2 * n - 1,true);
			vector<string> (n,string(n,'.'));
			vector<vector<string>> ans;
			back_tracking(k,column,ldiag,rdiag,n,ans,tmp);
			return ans;

		}
		void back_tracking(int k,vector<bool> &cloumn,vector<bool> &ldiag,vector<bool> &rdiag,int n,vector<vector<string>> &ans,vector<string> &tmp){
			if(k == n){
				ans.push_back(tmp);
				return ;
			}

			for(int i = 0,i < n,i++){
				if(column[i] && ldiag[i + k] && rdiag[n - 1 - k + i]){
					tmp[k][i] = 'Q';
					column[i] = false;
					ldiag[i + k] = false;
					rdiag[n - 1 - k + i] = false;
					back_tracking(k + 1,column,ldiag,rdiag,n,ans,tmp);
					column[i] = true;
					ldiag[i + k] = true;
					rdiag[n - 1 - k + i] = true;
					tmp[k][i] = '.';
				}
			}
		}
};

int main(){
	return 0;
}

