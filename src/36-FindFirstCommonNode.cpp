


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int head1_len =0;
        int head2_len = 0;
        ListNode *tree1 = pHead1;
        ListNode *tree2 = pHead2;
        while( (tree1 =tree1->next) )++head1_len;
        while( (tree2 = tree2->next)) ++head2_len;
        int gap=0;
        if(head1_len>head2_len){
            gap = head1_len-head2_len;
            tree1 = pHead1;
            tree2 =pHead2;
        }else
        {
            gap = head2_len-head1_len;
            tree1 = pHead2;
            tree2 =pHead1;
        }
        while (gap--)
        {
            tree1 = tree1->next;
        }
        while (tree1 && tree2 && tree1 != tree2)
        {
           tree1 = tree1->next;
           tree2 =tree2->next;
        }

        return tree2;

    }


   ListNode* FindFirstCommonNode2( ListNode* pHead1, ListNode* pHead2) {
        ListNode *ta = pHead1, *tb = pHead2;
        while (ta != tb) {
            ta = ta ? ta->next : pHead2;
            tb = tb ? tb->next : pHead1;
        }
        return ta;
    }
};

int main(int argc, const char** argv) {

    ListNode node1(12);
    ListNode node2(34);
    ListNode node3(34);

    ListNode node4(12);
    ListNode node5(34);
    ListNode node6(34);
    node1.next = &node2;
    node2.next = &node4;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    


    Solution solution;
    solution.FindFirstCommonNode(&node1,&node3);

    return 0;
}