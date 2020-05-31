class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty())
            return vector<vector<int>>();
        sort(candidates.begin(), candidates.end());
        
        vector<int> combo;
        vector<vector<int>> result;
        isValid(candidates, result, combo, target, 0);
        sort( result.begin(), result.end() );
        result.erase( unique( result.begin(), result.end() ), result.end() );
        return result;
        
    }
    
    void isValid(const vector<int> &candidates, vector<vector<int>> &result, vector<int> &combo, const int target, const int idx) {
        if(!target) {
            result.push_back(combo);
            return;
        }
        
        for(int i = idx; i != candidates.size() && target >= candidates[i]; i++) {
            combo.push_back(candidates[i]);
            isValid(candidates, result, combo, target - candidates[i], i+1);
            combo.pop_back();
        }
    }
};
