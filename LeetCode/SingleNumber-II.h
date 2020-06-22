class Solution {
public:
    int singleNumberSort(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size() - 1) {
            if(i == nums.size() - 1)
                return nums[i];
            if(nums[i] == nums[i + 1])
                i += 3;
            else
                return nums[i];
        }
        
        return nums[i];
    }
    
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> set;
        for(const auto &num : nums) {
            set[num]++;
        }
        
        for(const auto &elem : set)
            if(elem.second == 1)
                return elem.first;
        
        return 0;
    }
};
