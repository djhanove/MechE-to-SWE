class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // walkthrough array, incrementing profit if vector[i] < vector[i+1]
        if(prices.empty())
            return 0;
        int profit = 0;
        int buy = prices[0];
        for(size_t i = 0; i < prices.size() -1; i++)
            if(prices[i] < prices[i+1]) {
                buy = min(buy, prices[i]);
                profit = max(profit,prices[i+1] - buy); 
            }
        return profit;
    }
};
