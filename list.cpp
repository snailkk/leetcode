#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(){
		next = nullptr;
	}
	ListNode(int x):val(x),next(nullptr){}
	ListNode(int x,ListNode *ptr):val(x),next(ptr){}
};

ListNode * push_back(ListNode *head,int x){
	if(head == nullptr){
		head = new ListNode(x);
		return head;
	}
	ListNode *pre = nullptr,*cur = head;
	while(cur){
		pre = cur;
		cur = cur -> next;
	}
	pre -> next = new ListNode(x);
	return head;
}

ListNode * creat(int n){
	ListNode *head = nullptr;
	int x;
	cout << "input node val:"<< endl;
	cin >> x;
	head = new ListNode(x);
	n--;
	ListNode * pre = head;
	while(n--){
		cin >> x;
		pre -> next = new ListNode(x);
		pre = pre -> next;
	}
	return head;
}

void visit(ListNode *head){
	while(head){
		cout << head -> val << ' ';
		head = head -> next;
	}
	cout << endl;
}
int main(){
	int n;
	cout << "input the list size:" << endl;
	cin >> n;
	ListNode *head = creat(n);
	visit(head);
	return 0;
}
