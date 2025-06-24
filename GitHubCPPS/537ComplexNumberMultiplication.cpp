class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        pair<int, int>cn1, cn2;
        cn1 = str2cn(num1); cn2 = str2cn(num2);
        pair<int, int>cr;
        cr.first = cn1.first * cn2.first - cn1.second * cn2.second;
        cr.second = cn1.first * cn2.second + cn1.second * cn2.first;
        string res = cn2str(cr);
        return res;
    }
private:
    pair<int, int> str2cn(string& cs) {
        int pos = cs.find_first_of("+");
        if (pos != string::npos) {
            string r = cs.substr(0, pos);
            string c = cs.substr(pos + 1);
            return pair<int, int>{stoi(r), stoi(c)};
        }
        if (cs.find_first_of("i") != string::npos) {
            return pair<int, int>{0, stoi(cs)};
        }
        return pair<int, int>{stoi(cs), 0};
    }
    string cn2str(pair<int, int>& cn) {
        string cs;
        cs = to_string(cn.first);
        cs += '+';
        cs += to_string(cn.second) + 'i';
        return cs;
    }
};