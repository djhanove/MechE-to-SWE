class Solution {
public:
    string defangIPaddr(string address) {
        string tempstr = "";
        for(auto s : address) {
            if (s == '.')
                tempstr = tempstr + "[.]";
            else
                tempstr.push_back(s);
        }
        
        return tempstr;
        
    }
};
