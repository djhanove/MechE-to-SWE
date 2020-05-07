class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if(s.empty())
            return 0;
        std::bitset<256> bits;
        int count = 0;
        int sum = 0;
        size_t k = 0;
        for(size_t i = 0; i < s.length(); i++) {
            if(bits.test(s[i])) {
                sum = 0;
                bits.reset();
                i = k++;
            } 
            else {
                bits.flip(s[i]);
                sum++;
            }
            count = std::max(sum, count);

        }
        return count;
    }
};
