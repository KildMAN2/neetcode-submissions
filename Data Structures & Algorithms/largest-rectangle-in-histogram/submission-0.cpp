class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxA =0 ;
        stack <pair<int ,int >> stack;
        for(int i= 0 ; i< heights.size() ; i++)
        {
            int start = i;
            while(!stack.empty() && stack.top().second > heights[i])
            {
                int index =stack.top().first;
                int height = stack.top().second;
                maxA = max(maxA , height * (i - index));
                stack.pop();
                start = index; 

            }
            stack.push ({start,heights[i]});
        }
        while(!stack.empty())
        {
            int index =stack.top().first;
            int height = stack.top().second;
            maxA = max(maxA ,  height * (static_cast<int> (heights.size()) - index));
            stack.pop();
        }
        return maxA;
  
    }
};
