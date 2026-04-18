class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap; 
        for(int stone : stones)
        {
            maxHeap.push(stone);
        }
        while(maxHeap.size() > 1)
        {
            int player1 = maxHeap.top();
            maxHeap.pop();
            int player2 = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(player1 -player2);
        }
        maxHeap.push(0);
        return maxHeap.top();
        
    }
};
