class Solution {
public:
    int changeBT(int amount, vector<int>& coins) {
        //if(coins.empty() && amount ==0)
        //    return 1;
        sort(coins.begin(), coins.end());
        vector<vector<int>> combinations;
        vector<int> inter;
        combinationSum(coins, combinations, inter, amount, 0);
        return combinations.size();
        
    }
    
    void combinationSum(const vector<int> &coins, vector<vector<int>> &combinations, vector<int> &inter, const int target, const int begin)
    {
        if(!target) {
            combinations.push_back(inter);
            return;
        }
        
        for(int  i = begin; i < coins.size() && target >= coins[i]; i++) {
            inter.push_back(coins[i]);
            combinationSum(coins, combinations, inter, target - coins[i], i);
            inter.pop_back();
        }
        
        
    }
    
    int change(int amount, vector<int> &coins) {
        vector<int> result(amount+1, 0);
        result[0] = 1;
        for(const auto &coin : coins) {
            for(int i = coin; i <= amount; i++) {
                result[i] += result[i-coin];
            }
        }
        return result[amount];
    }
    
    
    
    
    
};
