class Solution {
public:
    bool validPalindrome(string s) {
        int diffCount = 0;
        size_t i = 0;
        size_t j = s.length() - 1;
        for(; i < j; i++, j--) {
            while(!isalnum(s[i]) && i < j) i++;
            while(!isalnum(s[j]) && i < j) j--;
            if(toupper(s[i]) != toupper(s[j])) { // need to check if the remainder of the string can be a palindrome
                // assuming that we skip either the i'th or j'th character, calculate if the remainder string is a palindrome
                return isPalindromeOptimized(s, i+1, j) || isPalindromeOptimized(s, i , j-1);
            }
        }
        
        return true;
        
        
    }
    
    
    
        bool isPalindromeOptimized(string &s, int i, int j){
        for (; i < j; i++, j--) { // Move 2 pointers from each end until they collide
            while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
            while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
            if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
        }

        return true;
    }
    
    
    
    
};
