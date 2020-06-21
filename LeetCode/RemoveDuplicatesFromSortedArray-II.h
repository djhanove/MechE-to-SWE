class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                length++;
                if(length > 2) {
                    nums.erase(nums.begin() + i--);
                }   
            }
            else
                length = 1;
        }
        
        return nums.size();
        
    }
};
