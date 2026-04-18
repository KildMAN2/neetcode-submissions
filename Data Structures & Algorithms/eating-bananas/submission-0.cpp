class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int t = *max_element (piles.begin(), piles.end());
        int res = t;
        while( l <= t)
        {
            int k = (l + t) /2;
            long long totalTime = 0; 
            for(int p : piles)
            {
                totalTime += ceil(static_cast<double> (p)/ k);
            }
            if(totalTime <= h)
            {
                res = k;
                t = k -1;
            }
            else
            {
                l = k + 1;
            }
        }
        return res;
        
    }
};
