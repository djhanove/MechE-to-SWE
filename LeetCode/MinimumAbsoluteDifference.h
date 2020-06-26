class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        if(arr.empty())
            return vector<vector<int>>();
        vector<vector<int>> res;
        int minDiff = INT_MAX;
        sort(arr.begin(), arr.end());
        for(int i = 1; i < arr.size(); i++) {
            minDiff = min(arr[i] - arr[i-1], minDiff);
        }
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] - arr[i-1] == minDiff)
                res.push_back({arr[i-1],arr[i]});
        }
        return res;
    }
};
