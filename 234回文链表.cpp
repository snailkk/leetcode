#include"list.hpp"
using namespace std;
class Solution {
public://快慢指针 + 反转链表应该能做到O(n)时间复杂度和O(1)空间复杂度
    bool isPalindrome(ListNode* head) {
	ListNode *pre = nullptr,*next,*slow = head,*fast = head;
	while(fast){//双指针 + 反转链表
		if(!fast -> next){//注意长度为奇数的链表
			ListNode * tmp = new ListNode(slow -> val);
			tmp -> next = pre;
			pre = tmp;
			break;
		}
		fast = fast -> next -> next;
		next = slow -> next;
		slow -> next = pre;
		pre = slow;
		slow = next;
	}
	while(slow -> val == pre ->val){//注意不是 slow == pre
		slow = slow -> next;
		pre = pre -> next;
		if(slow == nullptr){
			return true;
		}
	}
	return false;
    }
};
int main(){
	int n;
	cout << "input the list size:" << endl;
	cin >> n;
	ListNode *head = create(n);
	Solution s;
	if(s.isPalindrome(head)){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
	return 0;
}
