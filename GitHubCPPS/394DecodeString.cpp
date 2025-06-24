class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string curStr{ "" };
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) num = num * 10 + (c - '0');
            else if (c == '[') {
                numStack.push(num);
                strStack.push(curStr);
                num = 0;
                curStr = "";
            }
            else if (c == ']') {
                int rep = numStack.top(); numStack.pop();
                string tmp = strStack.top(); strStack.pop();
                while (rep--) tmp += curStr;
                curStr = tmp;
            }
            else {
                curStr += c;
            }
        }
        return curStr;
    }
};