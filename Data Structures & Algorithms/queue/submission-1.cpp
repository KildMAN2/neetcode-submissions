class Node{
    public: 
    int value;
    Node* next;
    Node * prev;
    Node(int value) : value(value) , next(nullptr) , prev(nullptr){}
};
class Deque {
    private:
    Node* dummyHead;
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
        Node* PrevNode = dummyTail->prev;
        PrevNode->next = toAdd;
        toAdd->prev = PrevNode;
        toAdd->next = dummyTail;
        dummyTail->prev = toAdd;
        
    }

    void appendleft(int value) {
        Node * toAdd = new Node(value);
        Node * nextNode = dummyHead->next;
        nextNode->prev = toAdd; 
        toAdd->next = nextNode;
        toAdd->prev = dummyHead;
        dummyHead->next = toAdd;
        
    }

    int pop() {
        if(isEmpty())
        {
            return -1;
        }
        Node * toPop = dummyTail->prev;
        Node* prevNode = toPop->prev;
        dummyTail->prev = prevNode;
        prevNode->next = dummyTail;
        int res = toPop->value;
        delete toPop;
        return res;
 

    }

    int popleft() {
        if(isEmpty())
        {
            return -1;
        }
        Node * toPop = dummyHead->next;
        Node* nextNode = toPop->next;
        dummyHead->next = nextNode;
        nextNode->prev = dummyHead;
        int res = toPop->value;
        delete toPop;
        return res;

    }
};
