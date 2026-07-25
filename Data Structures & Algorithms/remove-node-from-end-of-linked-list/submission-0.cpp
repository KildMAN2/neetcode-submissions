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
        ListNode * it = head;
        int size = 0 ; 
        while(it)
        {
            it = it->next; 
            size++;
        }
        int removeIndex = size - n ;
        if(head && removeIndex == 0)
        {
            return head->next;
        }
        it = head;
        for(int i = 0 ; i < size;i++)
        {
            if((i + 1) == removeIndex)
            {
                it->next = it->next->next;
                break;
            }
            it = it->next;
        }
        return  head;
        
    }
};
