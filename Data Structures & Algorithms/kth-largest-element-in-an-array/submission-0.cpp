class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , greater<int>> maxHeap;
        for(int n : nums)
        {
            maxHeap.push(n);
            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        return maxHeap.top();
        
    }
};
