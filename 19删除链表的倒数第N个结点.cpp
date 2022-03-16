#include"list.hpp"
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head,*slow = head;
        int cnt = 0;
        while(fast && fast -> next){
            cnt++;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(!cnt) return nullptr;
        int size = 0;
        if(!fast){
            size = 2 * cnt;
        }
        else{
            size = 2 * cnt + 1;
        }
        slow = head;
        fast = nullptr;
        for(int i = 0;i < size - n;i++){
            fast = slow;
            slow = slow -> next;
        }
        if(!fast) return slow -> next;
        fast -> next = slow -> next;
        return head;
    }
};
int main(){
    int n;
    cout << "input the list size:" << endl;
    cin >> n;
    ListNode * head = create(n);
    Solution s;
    ListNode * node = s.removeNthFromEnd(head,3);
    visit(node);
    return 0;
}