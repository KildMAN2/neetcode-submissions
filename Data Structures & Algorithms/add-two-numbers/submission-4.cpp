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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0 ;
        ListNode *dummy = new ListNode (-1);
        ListNode * it = dummy;
        while(l1 || l2 || carry)
        {
            int num1 = (l1 != nullptr) ? l1->val : 0;
            int num2 = (l2 != nullptr) ? l2->val : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            int val = sum % 10;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
            ListNode * toAdd = new ListNode(val);
            it->next = toAdd;
            it = it->next;
        }
        // if(carry > 0)
        // {
        //     ListNode * toAdd = new ListNode(carry);
        //     it->next = toAdd;
        //     it = it->next;  
        // }
        return dummy->next;
        
    }
};
