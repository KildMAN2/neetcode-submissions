class ListNode{
    public: 
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val , ListNode * next) : val(val), next(next){}
};
class LinkedList {
    private:
    ListNode* head;
    ListNode* tail;
public:
    LinkedList() {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode * curr = head->next;
        int i = 0 ;
        while (curr != nullptr)
        {
            if(i == index)
            {
                return curr->val;
            }
            i++;
            curr = curr->next;
        }
        return -1;

    }

    void insertHead(int val) {
        printValues();
        ListNode * toAdd = new ListNode(val);
        toAdd->next = head->next;
        head->next = toAdd;
        if(toAdd->next == nullptr)
        {
            tail = toAdd;
        }
        printValues();
        
    }
    
    void insertTail(int val) {
        printValues();
        ListNode * toAdd = new ListNode(val);
        tail->next = toAdd;
        tail = toAdd;
        printValues();
    }

    bool remove(int index) {
        ListNode * curr = head;
        int i = 0 ;
        while(curr != nullptr && i< index)
        {
            i++;
            curr = curr->next;
 
        }
        if(curr != nullptr && curr->next != nullptr)
        {
            if(curr->next == tail)
            {
                tail = curr;
            }
            ListNode * toDelete = curr->next;
            curr->next = toDelete->next;
            delete toDelete;
            cout<< "remove" << endl;
            printValues();
            return true;
        }
        return false;
        
    }

    vector<int> getValues() {
        printValues();
        vector<int> res;
        ListNode * curr = head->next;
        while(curr != nullptr)
        {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }
    void printValues()
    {
        ListNode * curr = head->next;
         int i = 0 ;
        while(curr != nullptr)
        {
            i++;
            cout << "the value of index " << i << " is : " << curr->val << endl;
            curr = curr->next;
        }
    }

};
