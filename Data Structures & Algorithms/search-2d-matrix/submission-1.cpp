class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0 ;
        int r = matrix[0].size() * matrix.size() -1;
        while( l <= r)
        {
            int mid = (r + l) /2;
            int col = mid % matrix[0].size();
            int row =  mid / matrix[0].size() ;
            if(target < matrix[row][col])
            {
                r = mid - 1;
            }
            else if (target > matrix[row][col])
            {
                l = mid + 1 ;
            }
            else 
            {
                return true;
            }
        }
        return false; 
    }
};
