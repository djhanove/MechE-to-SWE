class Solution {
public:
    vector<int> smallerNumbersThanCurrentBruteForce(vector<int>& nums) {   
        vector<int> result;
        for(size_t i=0; i < nums.size(); i++) {
            int count = 0;
            for(size_t j = 0; j < nums.size(); j++) {
                if(i != j) {
                    if(nums[j] < nums[i])
                        count++;
                }
            }
            result.push_back(count);
        }
        
        return result;
    }
    
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        if (nums.empty()) {
           return {}; 
        }
        vector<int> backup = nums;
        sort(backup.begin(), backup.end());
        int index = 0;
        int count = 0;
        unordered_map<int,int> record;
        while(index < backup.size()) {
            int currNum = backup[index];
            record.insert({currNum, count});
            while(index < backup.size() && backup[index] == currNum) {
                ++count;
                ++index;
            }
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            backup[i] = record[nums[i]];
        }
        return backup;
    }
};

