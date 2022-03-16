#include"list.hpp"
using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
	if(!head) return head;
	int pre_val = head -> val;
	ListNode *pre = head,*ret = head;
	head = head -> next;
	while(head){
		if(head -> val != pre_val){
			pre -> next = head;
			pre = head;
			pre_val = head -> val;
		}
		head = head -> next;
	}
	pre -> next = nullptr;
	return ret;
    }
};
int main(){
	int n;
	cout << "input the list size:" << endl;
	cin >> n;
	ListNode *head = create(n);
	Solution s;
	ListNode *node = s.deleteDuplicates(head);
	visit(node);
	return 0;
}
