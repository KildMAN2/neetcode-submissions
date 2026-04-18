class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1 ; // minimum speed of eating 
        int r = *max_element(piles.begin() , piles.end()); // finds the maximum value in piles O(n)
        int res = r;
        while( l<= r){
            int k = (r + l) /2 ;
            long long totalTime = 0;
            for(int pile : piles)
            {
                totalTime += ceil(static_cast<double> (pile) / k);
            }
            if(totalTime <= h)
            {
                res = k ;
                r = k - 1;
            }
            else
            {
                l = k + 1;
            }
        }
        return res;
        
    }
};
