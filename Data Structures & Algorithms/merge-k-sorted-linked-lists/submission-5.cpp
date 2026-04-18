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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        {
            return nullptr;
        }
        return devide(lists, 0 , lists.size() -1);
        
    }
private: 
    ListNode * devide (vector<ListNode*>& lists , int l , int r)
    {
        if(l > r)
        {
            return nullptr;
        }
        if(l == r)
        {
            return lists[l];
        }
        int mid = (l + r) / 2 ; 
        
        ListNode * left = devide(lists,l,mid);
        ListNode * right = devide(lists,mid + 1 , r);
        return merge(left,right);
    }
    ListNode * merge(ListNode* left, ListNode * right)
    {
        ListNode dummy(0);
        ListNode * head = &dummy;
        while(left && right)
        {
            if(left->val < right->val)
            {
                head->next = left;
                left = left->next;
            }
            else
            {
                head->next = right;
                right = right->next;
            }
            head = head->next;
        }
        if(left != nullptr)
        {
            head->next = left;
        }
        else
        {
            head->next = right;
        }
        return dummy.next;
    }
};
