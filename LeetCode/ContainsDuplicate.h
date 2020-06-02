class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty())
            return false;
        unordered_set<int> s;
        for(const auto num : nums) {
            if(!s.count(num))
                s.insert(num);
            else
                return true;
        }
        return false;
    }
};
