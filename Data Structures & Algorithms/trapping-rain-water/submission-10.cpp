class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0 ; 
        int left = 0 , right = height.size() - 1 ;
        int maxL = height[left];
        int maxR = height[right];
        int res = 0 ;
        while(left < right)
        {
            if(maxL < maxR)
            {
                left++;
                maxL = max(height[left] , maxL);
                res += maxL - height[left];
            }
            else
            {
                right--;
                maxR = max(height[right] , maxR);
                res += maxR - height[right];   
            }
        }
        return res;
        
    }
};
