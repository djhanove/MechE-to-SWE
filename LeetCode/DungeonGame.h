class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty())
            return 0;
        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size()));
        
        for(int i = dungeon.size() - 1; i >= 0; i--) {
            for(int j = dungeon[0].size() - 1; j >= 0; j--) {
                if(i == dungeon.size() - 1 && j == dungeon[0].size() - 1)
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                else if( i == dungeon.size() - 1) // can only move right
                    dp[i][j] = max(dp[i][j+1] - dungeon[i][j] , 1);
                else if( j == dungeon[0].size() - 1)
                    dp[i][j] = max(dp[i+1][j] - dungeon[i][j], 1); // can only move down
                else
                    dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]); //can move either right or down, find min
                
            }
        }
        return dp[0][0];
        
    }
};
