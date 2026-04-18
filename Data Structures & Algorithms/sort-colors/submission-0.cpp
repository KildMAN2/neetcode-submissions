class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        for(int num : nums)
        {
            count[num]++;
        }
        cout << count[0] << endl;
        cout << count[1] << endl;
        cout << count[2] << endl;

        int index = 0;
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < count[i]; j++)
            {
                nums[index++] = i;
            }
        }
        
    }
};