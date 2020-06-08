class Solution {
public:
    int coinChangeBT(vector<int>& coins, int amount) {
        if(coins.empty())
            return 0;
        sort(coins.begin(), coins.end());
        vector<vector<int>> result;
        vector<int> combination;
        combinationSum(coins, result, combination, amount, 0);
        int minimum = INT_MAX;
        for(const auto &res : result) {
            minimum = std::min(minimum, int(res.size()));
        }
        if(minimum == INT_MAX)
            return -1;

        return minimum;
    
    }
    
    void combinationSum(const vector<int> &coins, vector<vector<int>> &result, vector<int> &combination, const int target, const int idx) {
        if(!target) {
            result.push_back(combination);
            return;
        }
        
        for(int i = idx; i < coins.size() && target >= coins[i]; i++) {
            combination.push_back(coins[i]);
            combinationSum(coins, result, combination, target - coins[i], i);
            combination.pop_back();
        }
    }
    
    int coinChange(vector<int> &coins, int amount) {
        if(coins.empty())
            return -1;
        //sort(coins.begin(), coins.end()); //optimization
        vector<int> dp(amount+1, amount+1);
        
        // bottom up DP
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(coins[j] <= i)
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                //else
                    //break; //optimization
            }
        }
        
        if(dp[amount] != amount +1)
            return dp[amount];
        else
            return -1;
    }
    
};
