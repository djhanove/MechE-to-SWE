class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
    
    int binarySearch(const vector<int>& nums, const int low, const int high, const int target) {
        if(low > high)
            return -1;
        
        int mid = low + (high-low)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) return binarySearch(nums, mid+1, high, target);
        return binarySearch(nums, low, mid - 1, target);
    }
};
