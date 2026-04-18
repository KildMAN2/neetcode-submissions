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
        ListNode * itrator = head;
        int size = 0 ;
        while(itrator != nullptr)
        {
            size++;
            itrator = itrator->next;
        }
        int removeIndex = size -n ;
        if(removeIndex == 0)
        {
            return head->next;
        }
        itrator = head;
        for(int i = 0 ; i< size; i++)
        {
            if((i + 1) == removeIndex)
            {
                itrator->next = itrator->next->next;
                break;
            }
            itrator = itrator->next;

        }
        return head;

    }
};
