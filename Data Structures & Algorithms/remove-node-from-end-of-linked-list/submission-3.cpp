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
        int listLen = 0 ; 
        ListNode * it = head;
        while(it != nullptr)
        {
            it = it->next;
            listLen++;
        }
        it = head; 
        int counter = 0 ; 
        if(listLen - n == 0)
        {
            return it->next;
        }
        ListNode * curr = head;
        while(it && counter + 1 < listLen - n )
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
