class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> sets;
        int count = 0;
        for(auto str : J)
            sets.insert(str);
        
        for(auto str : S)
            if(sets.count(str))
                count++;
        
        return count;
    }
};
