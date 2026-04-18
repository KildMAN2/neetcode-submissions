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
    void reorderList(ListNode* head) {
        ListNode * fast = head->next;
        ListNode * slow = head;
        while(fast && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * second = slow->next;
        ListNode * curr = slow->next = nullptr;
        while(second != nullptr)
        {
            ListNode * next = second->next;
            second->next = curr;
            curr = second;
            second = next;
        }
        ListNode * first = head;
        second = curr;
        while(second != nullptr)
        {
            ListNode * next1 = first->next;
            ListNode * next2 = second->next;
            first->next = second;
            first = next1;
            second->next = first;
            second = next2;
        }
        
    }
};
