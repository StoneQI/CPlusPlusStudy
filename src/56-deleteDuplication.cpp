
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

    //直接删除法

        ListNode* deleteDuplication2(ListNode* pHead)
        {   
            //自己构建辅助头节点，避面单独讨论头节点的情况
            ListNode *vhead = new ListNode(-1);
            vhead->next = pHead;
            ListNode *pre = vhead, *cur = pHead;        
            while (cur) {
                if (cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                    while (cur->next && cur->val == cur->next->val) {
                        cur = cur->next;
                    }
                    cur = cur->next;
                    pre->next = cur;
                }
                else {
                    pre = cur;
                    cur = cur->next;
                }
            }
            return vhead->next;
        }
};

