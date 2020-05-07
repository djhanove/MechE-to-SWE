class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> mymap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            if(i < s.length()-1 && mymap.at(s[i]) < mymap.at(s[i+1]))
                sum -= mymap.at(s[i]);
            else
                sum += mymap.at(s[i]);
        }

        
        return sum;
    }
};