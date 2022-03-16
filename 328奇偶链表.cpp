#include"list.hpp"
using namespace std;
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
	ListNode *odd = head,*ret = head,*tmp2;//tmp2用来记住上一个偶数位置的地址
	int i = 1;
	while(head){
		if(i % 2 == 1 && i != 1){
			ListNode *tmp = odd -> next;
			odd -> next = head;
			tmp2 -> next = head -> next;
			head -> next = tmp;
			odd = head;
			head = tmp2;
		}
		else{
			tmp2 = head;
		}
		head = head -> next;
		i++;
	}
	return ret;
    }
};
int main(){
	int n;
	cout << "input the list size:" << endl;
	cin >> n;
	ListNode *head = create(n);
	Solution s;
	ListNode *ret = s.oddEvenList(head);
	visit(ret);
	return 0;
}
