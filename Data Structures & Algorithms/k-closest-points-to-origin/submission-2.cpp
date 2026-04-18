class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>maxHeap;
        for(auto point : points)
        {
            int dist = point[0]*point[0] + point[1]*point[1];
            pair<int,pair<int,int>> toAdd = {dist ,{point[0],point[1]}};
            maxHeap.push(toAdd);
            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        vector<vector<int>> res;
        while(maxHeap.size() > 0 )
        {
            pair<int,pair<int,int>> toAdd = maxHeap.top();
            maxHeap.pop();
            res.push_back({toAdd.second.first,toAdd.second.second});
        }
        return res;
        
    }
};
