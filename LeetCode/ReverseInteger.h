class Solution {
public:
    int reverse(int x) {

        int reversed = 0;
        
        while(x)
        {
            if(INT_MAX/10 < reversed) return 0;
            if(INT_MIN/10 > reversed) return 0;
            reversed = reversed * 10 + x % 10;
            x/=10;
        }
        return reversed;
    }
};
