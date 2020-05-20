class Solution {
public:
    int subtractProductAndSum(int n) {
        int rem = 0;
        int product = 1;
        int sum = 0;
        
        while(n>0) {
            rem = n%10;
            n = (n-rem)/10;        
            product *= rem;
            sum += rem;
        }
        
        return product - sum;
        
    }
};
