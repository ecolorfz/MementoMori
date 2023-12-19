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



/**
 * 160. 相交链表
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)return NULL;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1!=p2){
            p1 = p1==NULL?headB:p1->next;
            p2 = p2==NULL?headA:p2->next;
        }
        return p1;
    }
};