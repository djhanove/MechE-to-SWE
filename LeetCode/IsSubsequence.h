class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while(i < s.size() && j < t.size()) {
            if(t[j] == s[i]) {
                i++;
                if(i==s.size())
                    return true;
            }
            j++;
        }
        return i == s.size();
        
    }
};
