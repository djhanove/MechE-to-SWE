class Solution {
public:
    int removeDuplicatesBruteForce(vector<int>& nums) {
        if(nums.empty())
            return 0;
        size_t i = 0, j = 1;
        for (; i < nums.size() - 1; i++, j++)
        {
            if(nums[i] == nums[j]) {
                nums.erase(nums.begin() + i); // erase is very ineffective because it causes the array to shift all elements over
                i--;
                j--;
            }

        }
        return nums.size();
    }
    
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int slow=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=nums[i-1])
                nums[slow++] = nums[i];
        }
        return slow;
    }
    
    
};
