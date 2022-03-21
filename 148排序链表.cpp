#include"list.hpp"
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> ret;
        while(head){
            ret.push_back(head);
            head = head -> next;
        }
        sort(ret.begin(),ret.end());
        for(int i = 1;i < ret.size();i++){
            ret[i-1] ->next = ret[i];
        }
        return ret[0];
    }
};

int main(){
    int n;
    cout << "input the list size:" << endl;
    cin >> n;
    ListNode * head = create(n);
    Solution s;
    ListNode * ret = s.sortList(head);
    visit(ret);
}