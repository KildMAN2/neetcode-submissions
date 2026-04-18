class Node{
    public:
    int val;
    Node * next;
    Node * prev;
    Node(int val) : val(val), next(nullptr), prev(nullptr){}
};
class Deque {
    private:
    Node * dummyHead;
    Node * dummyTail;
public:

    Deque() {
        dummyHead = new Node(0);
        dummyTail = new Node(0);

        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    bool isEmpty() {
        return dummyHead->next == dummyTail;
    }

    void append(int value) {
        Node * toAdd = new Node(value);
        toAdd->prev =  dummyTail->prev;
        dummyTail->prev->next = toAdd ;
        toAdd->next = dummyTail;
        dummyTail->prev = toAdd;
    }

    void appendleft(int value) {
        Node * toAdd = new Node(value);
        Node * next = dummyHead->next;
        next->prev = toAdd;
        toAdd->next = next;
        toAdd->prev = dummyHead;
        dummyHead->next = toAdd;
        
    }

    int pop() {
        if(dummyHead->next == dummyTail)
        {
            return -1;
        }
        Node * toRemove =  dummyTail->prev;
        Node* before = toRemove->prev;
        before->next = toRemove->next;
        dummyTail->prev = before;
        int value = toRemove->val;
        delete toRemove;
        return value;
    }

    int popleft() {
        if(dummyHead->next == dummyTail)
        {
            return -1;
        } 
        Node * toRemove =  dummyHead->next;
        Node* after = toRemove->next;
        after->prev = toRemove->prev;
        dummyHead->next = after;
        int value = toRemove->val;
        delete toRemove;
        return value;

    }
};
