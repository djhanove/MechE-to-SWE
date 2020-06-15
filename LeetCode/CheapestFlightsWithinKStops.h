class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        queue<vector<int>> q;
        vector<vector<vector<int>>> adjList(n);
        
        for(const auto f : flights) {
            adjList[f[0]].push_back({f[1],f[2]});
        }
        
        q.push({src, 0, -1});
        
        int minCost = INT_MAX;
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            if(cur[0] == dst) {
                minCost = min(minCost, cur[1]);
                continue;
            }
            
            for(const auto city : adjList[cur[0]]) {
                if(cur[2] + 1 <= K && cur[1] + city[1] < minCost) {
                    q.push({city[0], city[1] + cur[1], cur[2] + 1});
                }
            }
        }
       return minCost == INT_MAX ? -1 : minCost;
    }
};
