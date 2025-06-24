class Solution {
public:
    bool isValid(string s) {
        stack<char> op;
        for (char ch : s) {
            int c = ch;
            if (c == '(' || c == '{' || c == '[') op.push(c);
            if (op.empty()) return false;
            if (c == ')') {
                if (op.top() != '(') return false;
                op.pop();
            }
            if (c == '}') {
                if (op.top() != '{') return false;
                op.pop();
            }
            if (c == ']') {
                if (op.top() != '[') return false;
                op.pop();
            }
        }
        if (op.empty()) return true;
        return false;
    }
};