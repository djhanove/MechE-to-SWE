class Solution {
public:
    int removeElementBruteForce(vector<int>& nums, int val) {
        if(nums.empty())
            return 0;
        int count = 0;
        for(size_t i = 0; i < nums.size(); i++)
            if(nums[i] == val) {
                nums.erase(nums.begin()+i); // erase is a very inefficient method to use
                i--;
            }
        return nums.size();
    }
    int removeElementStdLib(vector<int>& nums, int val) {
        return std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), val));
        // distance returns the number of elements traveled
    }
    
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != val) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};
