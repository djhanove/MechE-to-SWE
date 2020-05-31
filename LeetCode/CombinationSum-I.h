class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
            return vector<vector<int>>();
        sort(candidates.begin(), candidates.end()); // sort the input array for an easier time with backtracking
        vector<vector<int>> result;
        vector<int> tempVec;
        int idx = 0;
        int globalIdx = 0;
        isValid(candidates, target, result, tempVec, 0);
        return result;
        
    }
    
    void isValid(const vector<int> &candidates, const int target, vector<vector<int> > &res, vector<int> &combination, const int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            isValid(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
