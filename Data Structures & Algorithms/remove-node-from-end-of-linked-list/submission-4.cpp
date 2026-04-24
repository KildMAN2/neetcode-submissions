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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * prev = head;
        ListNode * first = head;
        int size = 0;
        while(first)
        {
            first = first->next;
            size++;
        }
        first = head;
        int index = size - n  ;
        if(index ==0)
        {
            return head->next;
        }
        while(first  && index)
        {
            prev = first;
            first = first->next;
            index--;
        }
        prev->next = prev->next->next;
        return head;
        
    }
};
