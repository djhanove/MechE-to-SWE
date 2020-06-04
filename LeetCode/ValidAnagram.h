class Solution {
public:
    bool isAnagramSort(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        vector<int> chararray(26,0);
        for(int i = 0; i < s.size(); i++) {
            chararray[s[i] - 'a']++;
            chararray[t[i] - 'a']--;
        }
        for(const auto &c : chararray) {
            if (c != 0)
                return false;
        }
        return true;
        
        
    }
};
