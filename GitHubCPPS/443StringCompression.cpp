class Solution {
public:
    int compress(vector<char>& chars) {
        int repeat = 0;
        char prev = -1;
        std::vector<char> result;
        for (char c : chars) {
            if (c == prev) { repeat++; continue; }
            if (repeat == 0) { prev = c; repeat = 1; continue; }
            if (repeat == 1) {
                result.push_back(prev);
                prev = c;
                continue;
            }
            else { // more than 2 repeats
                pushRepeat(result, repeat, prev);
                prev = c; repeat = 1;
            }
        }
        if (repeat == 1) result.push_back(prev);
        else if (repeat > 1) pushRepeat(result, repeat, prev);
        chars = result;
        return chars.size();

    }
private:
    void pushRepeat(std::vector<char>& res, int rep, char cc)
    {
        std::string str = std::to_string(rep);
        res.push_back(cc);
        for (char c : str) res.push_back(c);
    }
};