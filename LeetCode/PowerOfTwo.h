class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int result = 1;
        while(result < n && INT_MAX/2 > result && INT_MIN/2 < result)
            result *= 2;
        
        return result == n;
        
    }
};
