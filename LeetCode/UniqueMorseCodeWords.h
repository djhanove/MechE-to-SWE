class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char, string> charToMorse = {
            {'a',".-"}, {'b', "-..."},
            {'c', "-.-."}, {'d', "-.."},
            {'e', "."}, {'f', "..-."},
            {'g', "--."}, {'h', "...."},
            {'i', ".."}, {'j', ".---"},
            {'k', "-.-"}, {'l', ".-.."},
            {'m', "--"}, {'n', "-."},
            {'o', "---"}, {'p', ".--."},
            {'q', "--.-"}, {'r', ".-."},
            {'s', "..."}, {'t', "-"},
            {'u', "..-"}, {'v', "...-"},
            {'w', ".--"}, {'x', "-..-"},
            {'y', "-.--"}, {'z', "--.."}};    
        
        unordered_set<string> stringSet;
        for(auto word : words) {
            string tempstr;
            for( auto c : word) {
                tempstr += charToMorse.at(c);
            }
            if(!stringSet.count(tempstr)) {
                stringSet.insert(tempstr);
            }
        }
        
        
        return stringSet.size();
    }
};
