/*Leetcode 148. Sort List*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
    Sort a linked list in O(n log n) time using constant space complexity.
    Example 1:
    Input: 4->2->1->3
    Output: 1->2->3->4
    Example 2:
    Input: -1->5->3->4->0
    Output: -1->0->3->4->5

*/
/*
对链表自顶向下归并排序的过程如下。

找到链表的中点，以中点为分界，将链表拆分成两个子链表。寻找链表的中点可以使用快慢指针的做法，快指针每次移动 2 步，慢指针每次移动 1 步，当快指针到达链表末尾时，慢指针指向的链表节点即为链表的中点。

对两个子链表分别排序。

将两个排序后的子链表合并，得到完整的排序后的链表。可以使用「21. 合并两个有序链表」的做法，将两个有序的子链表进行合并。

上述过程可以通过递归实现。递归的终止条件是链表的节点个数小于或等于 1，即当链表为空或者链表只包含 1 个节点时，不需要对链表进行拆分和排序。

*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head,ListNode* tail) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
 //注意边界条件，当head->next == tail时，说明链表只有一个节点，此时不需要排序，直接返回head即可。
        ListNode* sp = head;
        ListNode* fp = head;
        while(fp!=tail){
            sp = sp->next;
            fp = fp->next;
            if(fp!=tail)fp = fp->next;
        }
        ListNode* mid = sp;
        return merge(sortList(head,mid),sortList(mid,tail));
    }

    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* dummynode = new ListNode();
        ListNode* tmp = dummynode;
        ListNode* tmp1 = a,* tmp2 = b;
        while(tmp1!=nullptr&&tmp2!=nullptr){
            if(tmp1->val<=tmp2->val){
                tmp->next = tmp1;
                tmp1 = tmp1->next;
            }
            else{
                tmp->next = tmp2;
                tmp2 = tmp2->next;
            }
            tmp = tmp->next;
        }
        if(tmp1!=nullptr){
           tmp->next = tmp1;
        }
        else tmp->next = tmp2;
        return dummynode->next;
    }
};


/*
56. 合并区间

思路简单,先排序，然后遍历一遍，如果当前区间的左端点小于等于上一个区间的右端点，那么就合并，否则就不合并。
记注vector操作，比如begin end push_back size等
*/

class Solution {
public:
    int max(int a,int b){
        if(a>b)return a;
        else return b;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        int mIdx = 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=merged[mIdx][1]){
                merged[mIdx][1] = max(merged[mIdx][1],intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
                mIdx++;
            } 
        }
        return merged;
    }
};

/*
    179.最大数
    给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

*/

#include <string>
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(int i=0;i<nums.size();i++){
            snums.push_back(to_string(nums[i]));
        }
        sort(snums.begin(),snums.end());
        string res = "";
        if(snums.size()==1)return snums[0];
        for(int i=snums.size()-1;i>0;i-=1){
            string tmp1 = snums[i] + snums[i-1];
             
            string tmp2 = snums[i-1] + snums[i];
            
            
            if(tmp1>tmp2)res+=snums[i];
            else {
                if(snums[i]==snums[i-1]&&snums[i]=="0"&&res=="")continue;
                res+=snums[i-1];
                snums[i-1] = snums[i];
            }
        }
        res+=snums[0];
        return res;
    }
};