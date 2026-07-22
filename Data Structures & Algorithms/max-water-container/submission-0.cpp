class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0 , r = heights.size() -1;
        int maxArea = 0 ;
        while(l < r)
        {
            maxArea = max(maxArea,((r - l) * min(heights[l] , heights[r])));
            if(heights[l] < heights[r])
            {
                l++;
            }
            else
            {
                r--;
            }   
        }
        return maxArea;
        
    }
};
