class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        
        std::istringstream ss(s);
        int size = 0;
        string tempstr;
        while(ss >> tempstr) {
            size = tempstr.length();
        }
        return size;
    }
};
