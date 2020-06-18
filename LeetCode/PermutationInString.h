class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    
        int map[26] = {0};
        for(const auto &c : s1)
            map[c - 'a']++; // get frequency of each char in s1
        
        int i= 0, j = 0;
        int charCount = s1.size();
        while(j < s2.size()) {
            //move j until j - i == len(p)
            if(map[s2.at(j++) - 'a']-- > 0)
                charCount--;
            
            if(!charCount)
                return true;
            if(j - i == s1.size() && map[s2.at(i++) - 'a']++ >= 0) 
                charCount++;
        }
        return false;
    }
    
};
