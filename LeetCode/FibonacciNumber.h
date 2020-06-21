class Solution {
public:
    std::vector<int> dp;
    Solution() : dp(31) {}
    int fib(int N) {
        if(N == 0)
            return 0;
        if(dp[N] != 0) {
            return dp[N];
        }
        int result;
        if(N == 1 || N == 2) {
            result = 1;
        }
        else
            result = fib(N-1) + fib(N-2);
        dp[N] = result;
        return result;
        
    }
};
