class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        int idx = 0;
        for(auto num : nums) {
            while (num > 0)
            {
                num /= 10;
                count++;
            }
            if(count%2 == 0)
                idx++;
            count = 0;
        }
        
        return idx;
        
    }
};
