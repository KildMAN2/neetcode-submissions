class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> wariores;
        for(int s : stones)
        {
            wariores.push(s);
        }
        while(wariores.size() > 1)
        {
            int player1 = wariores.top();
            wariores.pop();
            int player2 = wariores.top();
            wariores.pop();
            wariores.push(player1 - player2);
        }
        wariores.push(0);
        return wariores.top();

        
    }
};
