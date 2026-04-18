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
        return devide(lists , 0 , lists.size() -1);

        
    }
    private: 
        ListNode* devide(vector<ListNode*> & lists , int l , int r)
        {
            if(l > r)
            {
                return nullptr;
            }
            if(l == r)
            {
                return lists[l];
            }
            int mid = (l + r) /2;
            ListNode* left = devide(lists , l, mid);
            ListNode * right = devide(lists , mid+1 , r);
            return merge(left, right);
        }
        ListNode * merge (ListNode * L1, ListNode * L2)
        {
            ListNode dummy (0);
            ListNode * curr = &dummy;
            while(L1 && L2)
            {
                if(L1->val > L2->val)
                {
                    curr->next = L2;
                    L2 = L2 ->next;
                }
                else
                {
                    curr->next = L1;
                    L1 = L1->next;
                }
                curr = curr->next;
            }
            if(L1 != nullptr)
            {
                curr->next = L1;
            }
            else
            {
                curr->next = L2;
            }
            return dummy.next;
        }
};
