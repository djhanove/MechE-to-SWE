class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;

        int sum = 0;
        int ans = nums[0];
        for(size_t i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(sum, ans);
            sum  = max(sum, 0);
        }
        
        return ans;
    }
};
