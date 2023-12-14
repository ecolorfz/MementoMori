/*反转链表*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        

        ListNode *p1 = nullptr;
        ListNode *p2 = head;

        while (p2) {
            ListNode* tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }
        return p1;
    }
};