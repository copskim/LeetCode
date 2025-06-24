class Solution {
private:
	vector<char>at;
public:
	int countCharacters(vector<string>& words, string chars) {
		at.resize(26);
		for (char c : chars) { at[c - 'a']++; }
		int tlength = 0;
		for (string s : words) {
			if (sformed(s)) tlength += s.size();
		}
		at.resize(0);
		return tlength;
	}
private:
	bool sformed(string s) {
		vector<char>wt(at);
		for (char c : s) {
			if (!wt[c - 'a']) return false;
			wt[c - 'a']--;
		}
		return true;
	}
};