class Solution {
public:
    bool isPalindromeString(int x) {
        if(x < 0 || (x > 0 && x % 10 == 0)) // negative signs or multiples of 10 won't work i.e. -112, 10, 100, 50, etc.
            return false;
        int temp = 0;
        std::string str = std::to_string(x);
        std::string placeholder;
        for(char c : str)
        {
            placeholder += str.back();
            str.pop_back();
        }
        return std::stol(placeholder) == x;
            
        
    }
    
    bool isPalindrome(int x) {
        if(x < 0 || (x > 0 && x % 10 == 0)) // negative signs or multiples of 10 won't work i.e. -112, 10, 100, 50, etc.
            return false;
        long temp = x;
        long val = 0; // need to use a long here to avoid int overflow
        while (temp > 0) {
            val = val*10 + (temp%10);
            temp/=10;
        }
        return val == x;
    }
};
