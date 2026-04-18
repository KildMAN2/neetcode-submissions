class ListNode{
    public: 
    int val; 
    ListNode * next;

    ListNode(int val) : val(val) , next (nullptr){}
    ListNode(int val, ListNode * next) : val(val) , next (next) {}
};
class LinkedList {
    private:
    ListNode * head;
    ListNode * tail; 

public:
    LinkedList() {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode * it = head->next;
        int i = 0;
        while ( it != nullptr)
        {
            if(i == index)
            {
                return it->val;
            }
            it = it->next;
            i++;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode * toAdd = new ListNode(val);
        ListNode * next = head->next;
        
        if(next == nullptr)
        {
            tail = toAdd;
        }
        toAdd->next = next;
        head->next = toAdd;
    }
    
    void insertTail(int val) {
        ListNode* toAdd = new ListNode(val);
        tail->next = toAdd;
        tail = toAdd;
    }

    bool remove(int index) {
        ListNode * it = head;
        int i = 0 ;
        while (i< index && it != nullptr)
        {
            i++;
            it = it->next;
        }
        // not the tail or not legal 
        if(it != nullptr && it->next != nullptr)
        {
            // the ith is the tail;
            if(it->next == tail)
            {
                tail = it;
            }
            ListNode * toRemove = it->next;
            it->next = toRemove->next;
            delete toRemove;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        ListNode * it = head->next;
        vector<int>res;
        while(it != nullptr)
        {
            res.push_back(it->val);
            it = it->next;
        }
        return res;
    }
};
