class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0; 
        int r = rows * cols - 1 ;
        while(l <= r)
        {
            int mid = (r + l) /2 ;
            int row = mid / cols;
            int col = mid % cols;
            if(target > matrix[row][col])
            {
                l = mid + 1;
            }
            else if ( target < matrix[row][col])
            {
                r = mid - 1;
            }
            else 
            {
                return true;
            }
        }
        return false;
        
    }
};
