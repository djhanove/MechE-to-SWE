class Solution {
public:
    vector<int> plusOneInelegant(vector<int>& digits) {
        if(digits.empty())
            return digits;
        int i = digits.size() -1;
        if(digits[i] == 9) {
            while (digits[i] == 9 && i >= 0) {
                digits[i--] = 0;
                if(digits[0] == 0) {
                    digits.insert(digits.begin(),1);
                    return digits;
                }
            }
            digits[i] += 1;

        }
        else
            digits[i] += 1;
        
        return digits;
    }
    
    
    vector<int> plusOne(vector<int>& digits) {
        for (int i=digits.size(); i--; digits[i] = 0)
            if (digits[i]++ < 9)
                return digits;
        digits[0]++;
        digits.push_back(0);
        return digits;
    }
        
};
