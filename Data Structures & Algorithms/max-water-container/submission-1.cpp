class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l  = 0, r = heights.size() - 1 ;
        int maxArea  = 0;
        while(l<r)
        {
            int area = (r-l) * min (heights[l],heights[r]);
            maxArea = max(maxArea,area);
            if(heights[l] > heights[r])
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return maxArea;

    }
};
