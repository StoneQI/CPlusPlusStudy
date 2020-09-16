#include "headers.h"


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;

        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if( fast == nullptr || fast->next == nullptr) return nullptr;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

int main(int argc, char const *argv[])
{
    ListNode a(1);
    ListNode b(2);
    a.next = &b;
   // b.next = &a;
    Solution sol;
    std::cout << sol.detectCycle(&a)->val << std::endl;
    
    return 0;
}
