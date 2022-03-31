#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return b == 0?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int main(){
    vector<int> arr = {1,2,3,4,5,6};
	for(const int& v:arr){
		cout << v << endl;
	}
}
