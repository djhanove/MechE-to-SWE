class Solution {
public:
    vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return vector<int> {i,j};
                }
            }
        }
    throw "No two idx found";
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;

        for (int i = 0; i<nums.size(); ++i) {
            auto it = imap.find(target - nums[i]); // search map trying to find complement to current idx

            if (it != imap.end()) // it will go to the end of the map if not key(complement) is not found
                return vector<int> {i, it->second}; 

            imap[nums[i]] = i; // didn't find the complement which matches the target, so add the idx to the map
        }
        throw "No two idx found";
    }    
    
};
