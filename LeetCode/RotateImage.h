class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        vector<vector<int>> tempMat = matrix;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                tempMat[j][matrix.size()-1-i] = matrix[i][j];
            }
                
        }
        
        matrix = tempMat;
        

        
    }
    
    
    
    void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int a = 0;
            int b = n-1;
            while(a<b){
                for(int i=0;i<(b-a);++i){
                    swap(matrix[a][a+i], matrix[a+i][b]);
                    swap(matrix[a][a+i], matrix[b][b-i]);
                    swap(matrix[a][a+i], matrix[b-i][a]);
                }
                ++a;
                --b;
            }
        }
};
