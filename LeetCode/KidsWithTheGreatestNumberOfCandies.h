class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = LONG_MIN;
        vector<bool> boolvec;
        
        for(auto c : candies)
            maxi = max(maxi,c);
        
        for(auto c : candies) {
            if (c+extraCandies >= maxi)
                boolvec.push_back(true);
            else
                boolvec.push_back(false);       
        }
        
        return boolvec;
        
    }
};
