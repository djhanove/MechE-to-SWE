class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // don't want to evaluate when i = m -1 && j = 0
        // OR when j = n-1 && i = 0
        for(size_t i = 0; i < m - 1; i++)
            for(size_t j = 0; j < n - 1; j++)
                if(!(i+1 == m-1 && j+1 == 0) || !(i+1 == 0 && j+1 == n-1))
                    if(matrix[i][j] != matrix[i+1][j+1] )
                        return false;
        
        return true;
                
                
        
    }
};
