#include"list.cpp"
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	int cnt = 0,flag = 0;
	ListNode *list1 = headA,*list2 = headB;
	while(list1 && list2){
	    list1 = list1 -> next;
	    list2 = list2 -> next;
	}
	while(list1){
	    flag = 1;
	    cnt++;
	    list1 = list1 -> next;
	}
	while(list2){
	    flag = 2;
	    cnt++;
	    list2 = lisr2 -> next;
	}
	list1 = headA;
	list2 = headB;
	while(cnt--){
	    if(flag == 1){
	        list1 = list -> next;
	    }
	    else{
		list2 = list2 -> next;
	    }
	}
	while(list1 != list2){
	    list1 = list1 -> next;
	    list2 = list2 -> next;
	}
	return list1;
    }
};
