class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0 , r = heights.size() -1;
        int maxA = 0 ;
        while( l<r)
        {
            int area = (r -l) * min(heights[l], heights[r]);
            maxA = max(maxA , area);
            if(heights[l] > heights[r])
            {
                r--;
            }
            else 
            {
                l++;
            }
            
        }
        return maxA;
    }
};
