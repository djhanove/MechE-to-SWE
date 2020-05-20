class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> vec;
        int count = 0;
        for(size_t i = 0; i < nums.size(); i++) {
            if(i%2 == 0)
                count = nums[i];
            else {
                while(count > 0) {
                    vec.push_back(nums[i]);
                    count--;
                }
            }
        }
        return vec;
    }
};
