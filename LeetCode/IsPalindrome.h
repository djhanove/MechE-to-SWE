class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        s.erase(std::remove_if(s.begin(), s.end(), 
            []( auto const& c ) -> bool { return !std::isalnum(c); } ), s.end());
        
        size_t i =0;
        size_t j = s.length() - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(; i < s.length() && j >= 0; i++, j--)
        {
            if(s[i] != s[j])
                return false;
        }
        
        return true;   
    }
    
    bool isPalindromeOptimized(string s){
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
            while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
            while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
            if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
        }

        return true;
    }
};
