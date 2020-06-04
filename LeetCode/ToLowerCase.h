class Solution {
public:
    string toLowerCase(string str) {
        std::transform(str.begin(), str.end(), str.begin(),
    [](unsigned char c){ return std::tolower(c); });
        
        return str;
        
    }
};
