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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * start = head;
        ListNode * prev = nullptr;
        int count = 1 ;
        while(start && count != left)
        {

            prev = start;
            start = start->next;
            count++;
        }
        ListNode * next = nullptr;
        ListNode * prev2 = nullptr;
        ListNode * first = start;
        while(start && count <= right)
        {
            ListNode * next = start->next;
            start->next = prev2;
            prev2= start;
            start = next;
            count++;
        }
        if(first)
        {
            first->next = start;
        }
        if(prev)
        {
            prev->next = prev2;
        }
        if(left != 1)
        {
            return head;
        }
        else
        {
            return prev2;
        }


        
    }
};