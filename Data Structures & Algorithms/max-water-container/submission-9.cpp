class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0 ; 
        int l = 0 ; 
        int r = heights.size() -1 ;
        while(l< r)
        {
            int minHeight = min(heights[l] , heights[r]);
            maxArea = max(maxArea , minHeight * (r -l));
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
