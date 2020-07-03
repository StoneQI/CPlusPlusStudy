
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
         if (pHead==nullptr)
        {
            return nullptr;
        }
        ListNode *preP = pHead;
        ListNode *endP = pHead->next;
        bool isHeadDup = false;
        if (endP == nullptr)
        {
            return pHead;
        }
        while (endP != nullptr)
        {  
            if(endP->val == endP->next->val ){
                if (endP->val == pHead->val)
                {
                    isHeadDup = true;
                }
                preP->next = endP->next;
            }else{
                preP = endP;
            }
            endP = endP->next;
        }
        if(isHeadDup){
            return pHead->next;
        }else{
            return pHead;
        }
    }
};

