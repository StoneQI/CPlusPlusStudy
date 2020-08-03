#include "headers.h"

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        std::set<ListNode *> listSet;
        while (pHead && !listSet.count(pHead))
        {
            listSet.insert(pHead);
            pHead = pHead->next;
        }
        return pHead;
        
    }
};