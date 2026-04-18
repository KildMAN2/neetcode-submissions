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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * itrator1 = list1;
        ListNode * itrator2 = list2;
        ListNode dummy(0);
        ListNode * merged = &dummy;
        while(itrator1 && itrator2)
        {
            if(itrator1->val <= itrator2->val)
            {
                merged->next = itrator1;
                merged = merged->next;
                itrator1 = itrator1->next;
            }
            else
            {
                merged->next = itrator2;
                merged = merged->next;
                itrator2 = itrator2->next ;
            }

        }
        if(itrator2)
        {
            merged->next = itrator2;


        }
        if(itrator1)
        {
            merged->next = itrator1;
        }
        return dummy.next;
        
    }
};
