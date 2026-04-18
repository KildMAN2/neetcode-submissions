class KthLargest {
    private: 
    priority_queue<int, vector<int> , greater<int>> maxHeap;
    int k; 
public:
    KthLargest(int k, vector<int>& nums) {
        this-> k = k; 
        for(int num : nums)
        {
            maxHeap.push(num);
            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        
        
    }
    
    int add(int val) {
        maxHeap.push(val);
        if(maxHeap.size() > k)
        {
            maxHeap.pop();
        }
        return maxHeap.top();
        
    }
};
