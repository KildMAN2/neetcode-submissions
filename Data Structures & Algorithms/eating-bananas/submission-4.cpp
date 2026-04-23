class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int  l = 1 ;
        int r = *max_element(piles.begin() , piles.end());
        int res =r ;
        while( l <= r)
        {
            int k = (l + r) /2 ;
            long long totalTime = 0 ; 
            for(int p : piles)
            {
                totalTime += ceil(static_cast<double>(p) /k);
            }
            if( totalTime <= h)
            {
                r = k - 1;
                res = k;
            }
            else
            {
                l = k + 1;
            }
        }
        return res;

        
    }
};
