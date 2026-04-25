/*
            1           2        3           4             5   
    smallH   1.      12-> 1             
    largeH               2  



*/

class MedianFinder {
private:
    priority_queue<int>smallHeap;
    priority_queue<int,vector<int>,greater<int>> largeHeap;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        if(!largeHeap.empty() && largeHeap.top() < smallHeap.top())
        {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(smallHeap.size() > largeHeap.size() + 1)
        {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(smallHeap.size() + 1 < largeHeap.size())
        {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
        
    }
    
    double findMedian() {
        if(smallHeap.size() == largeHeap.size())
        {
            return (smallHeap.top() + largeHeap.top()) / 2.0;
        }
        else if(smallHeap.size() > largeHeap.size())
        {
            return smallHeap.top();
        }
        else
        {
            return largeHeap.top();
        }
        
    }
};
