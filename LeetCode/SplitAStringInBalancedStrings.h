class Solution {
public:
    int balancedStringSplit(string s) {
        if(s.empty())
            return 0;
        
        std::queue<char> rQ;
        std::queue<char> lQ;
        int count = 0;
        
        for(const auto& c : s) {
            if(c == 'L')
                lQ.push(c);
            else
                rQ.push(c);
        
            while(!lQ.empty() && !rQ.empty()) {
                lQ.pop();
                rQ.pop();
                if(lQ.empty() && rQ.empty())
                    count++;
            }
        }
        return count;
    }
    
    
    int balancedStringSplitOptimized(string s) {
        int res = 0, cnt = 0;
        for (const auto& c : s) {
            cnt += c == 'L' ? 1 : -1;
            if (cnt == 0) ++res;
        }
        return res;        
    }
    
    
    
};
        
        
