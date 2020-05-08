class Solution {
public:
    int searchInsertBruteForce(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int count = 0;
        for(size_t i =0; i < nums.size(); i++) {
            if(nums[i] < target) {
                count++;
            }
            else if (nums[i] == target)
                return i;            
        }
        return count;
        
    }
    
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int min = 0;
        int max = nums.size() - 1;
        while(min <= max) {
            int guess = min + (max - min)/2;
            if(nums[guess] < target)
                min = guess + 1;
            else
                max = guess - 1;
        }
        return min;
        
    }
    
    /*
    Let min = 0 and max = n-1.
    Compute guess as the average of max and min, rounded down (so that it is an integer).
    If array[guess] equals target, then stop. You found it! Return guess.
    If the guess was too low, that is, array[guess] < target, then set min = guess + 1.
    Otherwise, the guess was too high. Set max = guess - 1.
    Go back to step 2.
    */
};
