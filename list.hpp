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

ListNode * create(int n){
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
	while(head != nullptr){
		cout << head -> val << ' ';
		head = head -> next;
	}
	cout << endl;
}
ListNode * reverseCreate(int n){
	ListNode *head = nullptr;
	cout << "input the node val:" << endl;
	while(n--){
		int x;
		cin >> x;
		ListNode * newptr = new ListNode(x,nullptr);
		newptr -> next = head;
		head = newptr;
	}
	return head;
}
