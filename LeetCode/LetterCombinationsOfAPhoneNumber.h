class Solution {
public:
    unordered_map<char, string> MAP = {
            {'2' , "abc"},
            {'3' , "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9' , "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string>();
        vector<string> result;
        string tempStr;
        isValid(result, tempStr, digits, 0, 0);
        return result;
    }
    
    void isValid(vector<string> &result, string &tempStr, const string &digits, const int idx1, const int idx2) {
        if(idx1 >= digits.size()) {
            result.push_back(tempStr);
            return;
        }
        
        for(int i = 0; i < MAP.at(digits[idx1]).size(); i++) {
            tempStr.push_back(MAP.at(digits[idx1])[i]);
            isValid(result, tempStr, digits, idx1+1, i);
            tempStr.pop_back();
        }
        
        
        
    }
    
    
};
