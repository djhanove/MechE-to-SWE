class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        else if (strs.size() == 1)
            return strs.front();
        std::string prefix;
        std::string firstStr = strs.front();
        int k=0;
        int i=1;
        while(strs[i][k] == firstStr[k] && i < strs.size() && k < firstStr.length()) {
            i++;
            if(i == strs.size()) { // we made it through all the strings for the first char
                prefix += firstStr[k];
                i = 0;
                k++;
            }
        }
        return prefix;
    }
};
