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
        int listlen = 0; 
        ListNode * it = head; 
        while(it)
        {
            it = it->next;
            listlen++;
        }
        if(listlen - n == 0)
        {
            return head->next;
        }
        int counter = 0;
        it = head;
        ListNode* curr = head;
        while(it && counter + 1< listlen - n)
        {
            curr = it;
            it = it->next;
            counter++;
        }
        if(it && it->next)
        {
            it->next = it->next->next;
        }
        return head;
        
    }
};
