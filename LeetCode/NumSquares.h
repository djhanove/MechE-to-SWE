class Solution {
public:
    int numSquaresBackTrack(int n) {
        // k^2 = 2(k-1)^2 - (k-2)^2 + 2
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = 2*dp[i-1] - dp[i-2] + 2;
        }
        int tempSum = 0;
        int j = n;
        int nums = 0;
        while(true) {
            while(dp[j] > n)
                j--;
            cout<<"Nums in tempSum: " << nums << " TempSum: " << tempSum <<endl;
            if(tempSum < n) {
                tempSum += dp[j];
                nums++;
            }
            else if(tempSum > n) {
                tempSum -= dp[j];
                j--;
                nums--;
            }
            else {
                cout<<tempSum<<endl;
                break;
            }
        }
        return nums;
        
    }
    
    int numSquares(int n) {
    static vector<int> dp {0};
    while (dp.size() <= n) {
        int m = dp.size(), squares = INT_MAX;
        for (int i=1; i*i<=m; ++i)
            squares = min(squares, dp[m-i*i] + 1);
        dp.push_back(squares);
    }
    return dp[n];
}
};
