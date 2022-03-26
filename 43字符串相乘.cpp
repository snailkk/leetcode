#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        string ret = string("0");
        for(int i = num1.size() -1,q = 0; i>=0;i--,q++){
            string tmp;
            char c = '0',o = '0';
            for(int j = num2.size() - 1;j >= 0;j--){
                c = (((num1[i] - '0')*(num2[j] - '0') + (o - '0')) % 10) + '0';
                o = (((num1[i] - '0')*(num2[j] - '0') + (o - '0')) / 10) + '0';
                string cc;
                cc.push_back(c);
                tmp = cc + tmp;
                if(j == 0){
                    if(o != '0'){
                        string cc; 
                        cc.push_back(o);
                        tmp = cc + tmp;
                    }
                    string d = tmp + string(q,'0');
                    if(num1[i] == '0' || num2[j] == '0') d = string("0");
                    // cout << d << endl;
                    ret = add(ret,d);
                }
            }
        }
        return ret;
    }
    string add(string& a,string &b){
        int i = a.size() - 1;
        int j = b.size() - 1;
        string tmp;
        char c = '0',o = '0';
        for(;i >= 0 && j >=0 ;i--,j--){
            c = (((a[i] - '0') + (b[j] - '0') + (o - '0')) % 10) + '0';
            o = (((a[i] - '0') + (b[j] - '0') + (o - '0')) / 10) + '0';
            string cc;
            cc.push_back(c);
            tmp = cc + tmp;
        }
        while(i >= 0){
            c = (((a[i] - '0') + (o - '0')) % 10) + '0';
            o = (((a[i] - '0') + (o - '0')) / 10) + '0';
            string cc;
            cc.push_back(c);
            tmp = cc + tmp;
            i--;
        }
        while(j >= 0){
            c = (((b[j] - '0') + (o - '0')) % 10) + '0';
            o = (((b[j] - '0') + (o - '0')) / 10) + '0';
            string cc;
            cc.push_back(c);
            tmp = cc + tmp;
            j--;
        }
        if(o != '0'){
            string cc;
            cc.push_back(o);
            tmp = cc + tmp;
        }
        return tmp;
    }
};
int main(){
    string a = "123432423",b = "431234123412";
    Solution s;
    string c = s.multiply(a,b);
    cout << c << endl;
}