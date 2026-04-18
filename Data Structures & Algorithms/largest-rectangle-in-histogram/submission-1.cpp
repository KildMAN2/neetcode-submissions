class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack; 
        int maxArea = 0 ; 
        int n = heights.size();
        for(int i =0 ; i<= heights.size() ; i++)
        {
            while(!stack.empty() && ( i==n || heights[i] <= heights[stack.top()]))
            {
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1 ;
                maxArea = max (maxArea , width * height);
            }
            stack.push(i);
        }
        return maxArea;
    }
};
