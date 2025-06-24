class Solution {
public:
    int romanToInt(string s) {
        int iv = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'M') {
                iv += 1000;
            }
            else if (s[i] == 'D') {
                iv += 500;
            }
            else if (s[i] == 'C') {
                if (i + 1 < s.size()) {
                    if (s[i + 1] == 'M') {
                        iv += 900, i++;
                        continue;
                    }
                    else if (s[i + 1] == 'D') {
                        iv += 400; i++;
                        continue;
                    }
                }
                iv += 100;
            }
            else if (s[i] == 'L') {
                iv += 50;
            }
            else if (s[i] == 'X') {
                if (i + 1 < s.size()) {
                    if (s[i + 1] == 'C') {
                        iv += 90, i++;
                        continue;
                    }
                    else if (s[i + 1] == 'L') {
                        iv += 40; i++;
                        continue;
                    }
                }
                iv += 10;
            }
            else if (s[i] == 'V') {
                iv += 5;
            }
            else if (s[i] == 'I') {
                if (i + 1 < s.size()) {
                    if (s[i + 1] == 'X') {
                        iv += 9, i++;
                        continue;
                    }
                    else if (s[i + 1] == 'V') {
                        iv += 4; i++;
                        continue;
                    }
                }
                iv += 1;
            }
        }
        return iv;
    }
};