#include"list.hpp"
using namespace std;
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
	ListNode *ret = new ListNode,*pre = ret,*cur = head;
	while(1){
	    ListNode *list1 = cur;
	    if(!list1){
		break;
	    }
	    ListNode *list2 = cur -> next;
	    if(!list2){
	        pre -> next = list1;
		break;
	    }
	    cur = list2 -> next;
	    pre -> next = list2;
	    list2 -> next = list1;
	    pre = list1;
	    pre -> next = nullptr;
	}
	return ret -> next;
    }
};
int main(){
	int n;
	cout << "input the list size:" << endl;
	cin >> n;
	ListNode *head = create(n);
	Solution s;
	ListNode *ptr = s.swapPairs(head);
	visit(ptr);
	return 0;
}
