class Solution {
public:
    int maxProfitFirstPass(std::vector<int>& prices) {
        if(prices.empty())
            return 0;
        int buy = 0;
        int sum = 0;
        size_t i = 0;
        while(i < prices.size() -1) {
            if(prices[i] < prices[i+1]) { // buying opportunity
                buy = prices[i++]; // purchase, then increment count
                int profit = 0;
                while(profit < prices[i] - buy) { // continue incrementing until we decrease in profit or until we hit end
                    profit = prices[i++] - buy;
                    if(i > prices.size() - 1)
                        break;
                }
                sum += profit;
            }
            else // no good buying opportunity
                i++;
        }
        return sum;
    }
    
    int maxProfit(std::vector<int>& prices) {
        if(prices.empty())
            return 0;
        int sum = 0;
        for(size_t i = 0; i < prices.size()-1; i++) {
            if (prices[i+1] > prices[i]) sum += prices[i+1] - prices[i];
        }
        return sum;
    }
};
