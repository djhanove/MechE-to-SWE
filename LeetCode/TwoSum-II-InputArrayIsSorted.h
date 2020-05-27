class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.empty())
            return vector<int>();
        vector<int> result;
        for(int i = 0; i < numbers.size(); i++) {
            int targ = target - numbers[i];
            int complement = binarySearch(targ, numbers, i+1, numbers.size()-1);
            if(complement != -1) {
                result.push_back(i+1);
                result.push_back(complement+1);
                return result;
            }
                
        }
        
        return result;

        
    }
    
    int binarySearch(const int &target, const vector<int> &numbers, const int &low, const int &high) {
        if(low > high)
            return -1; // not found
        int mid = low + (high-low) / 2;
        if(numbers[mid] < target) {
            return binarySearch(target, numbers, mid + 1, high);
        }
        else if (numbers[mid] > target)
            return binarySearch(target,numbers, low, mid-1);
        else
            return mid;
    }
};
