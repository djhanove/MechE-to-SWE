class Solution {
public:
    int singleNumberFirstPass(vector<int>& nums) {
        unordered_map<int,int> map;
        sort(nums.begin(), nums.end());
        int target = nums[0];

        for(size_t i = 1; i <nums.size() - 1; i++) {
            if(target != nums[i] && nums[i] != nums[i+1])
                target = nums[i];
        }
        return target;
    }
    
    int singleNumber(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        unordered_set<int> s;
        for(const auto num : nums) {
            if(!s.count(num)) {
                s.insert(num);
            }
            else
                s.erase(num);
        }
        return (*s.begin());
    }
};
