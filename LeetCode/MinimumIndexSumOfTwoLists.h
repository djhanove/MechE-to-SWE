class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        if(list1.empty() || list2.empty())
            return vector<string>();
        unordered_map<string,int> s;
        int prefSum = INT_MAX;
        vector<string> result;
        for(size_t i = 0; i < list1.size(); i++) {
            s.insert({list1[i],i});
        }
        
        for(size_t i = 0; i < list2.size(); i++) {
            if(s.count(list2[i])) {
                if(prefSum > s.at(list2[i]) + i) {
                    result.clear();
                    result.push_back(list2[i]);
                    prefSum = s.at(list2[i]) + i;
                }
                else if(prefSum == s.at(list2[i]) + i) {
                    result.push_back(list2[i]);
                    prefSum = s.at(list2[i]) + i;
                }        
            }
        }
        
        return result;
        
    }
};
