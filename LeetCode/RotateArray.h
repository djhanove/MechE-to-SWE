class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty())
            return;
        vector<int> result(nums.size(),0);
        for(int i = 0; i < nums.size(); i++) {

            int rem = (i+k) % int(nums.size());
            result[rem] = nums[i];
            
        }
        swap(nums, result);
    }
};
