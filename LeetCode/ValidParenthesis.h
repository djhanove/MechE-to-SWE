    bool isValid(string s) {
        if(s.empty())
            return true;
        if(s.length() % 2 == 1)
            return false;

        std::stack<char> stk;
        for(char c : s) {
            if(c == '[' || c == '(' || c == '{')
                stk.push(c);
            else {
                if (stk.empty()) return false;
                if(c == ']' && stk.top() != '[') return false;
                if(c == '}' && stk.top() != '{') return false;
                if(c == ')' && stk.top() != '(') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
