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
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow  = slow->next;
        }
        ListNode * prev = nullptr;
        ListNode * first = slow;
        while(first)
        {
            ListNode * next = first->next;
            first->next = prev;
            prev = first;
            first = next;
        }
        ListNode * it = head;
        while(it && prev)
        {
            ListNode * next1 = it->next;
            ListNode * next2 = prev->next;
            it->next = prev;
            it = next1;
            prev->next = it;
            prev = next2;
        }
    }
};
