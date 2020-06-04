class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> m;
        for(int i = 0; i < s.size(); i++) {
            if(m.count(s[i])) {
                m[s[i]] = -1;
                //cout << "Erased Element: " << s[i] << endl;
            }
            else
                m.insert({s[i], i});
        }
        
        int mini = INT_MAX;
        for(auto i = m.begin(); i != m.end(); i++) {
            if(i->second > -1 && i->second < mini)
                mini = i->second;
        }
        
        return mini < INT_MAX ? mini : -1;
        
        
    }
};
