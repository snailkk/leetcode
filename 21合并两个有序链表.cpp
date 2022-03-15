#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(){
		next = nullptr;
	}
	ListNode(int x):val(x),next(nullptr){}//一定注意这里的next 赋值为nullptr
	ListNode(int x,ListNode *ptr):val(x),next(ptr){};
};
ListNode * create(int n){
	ListNode *head;
	int x;
	cout << "input the node val:" << endl;
	cin >> x;
	head = new ListNode(x);
	n--;
	ListNode *pre = head;
	while(n--){
		cin >> x;
		pre -> next = new ListNode(x);
		pre = pre -> next;
	}
	return head;
}
void visit(ListNode *head){
	while(head != nullptr){
		cout << head -> val << ' ';
		head = head -> next;
	}
	cout << endl;
}

class Solution{
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
		ListNode *head = new ListNode,*ptr = head;
		while(list1 && list2){
			if(list1 -> val < list2 -> val){
				ptr -> next = list1;
				list1 = list1 -> next;
			}
			else{
				ptr -> next = list2;
				list2 = list2 -> next;
			}
			ptr = ptr -> next;
		}
		ptr -> next = list1?list1:list2;
		free(head);
		return head -> next;
	}
};
int main(){
	int m,n;
	cout << "input the list1 size:" << endl;
	cin >> m;
	ListNode *list1 = create(m);
	visit(list1);
	cout << "input the list2 size:" << endl;
	cin >> n;
	ListNode *list2 = create(n);
	visit(list2);
	Solution s;
	ListNode *head = s.mergeTwoLists(list1,list2);
	visit(head);
	return 0;
}
