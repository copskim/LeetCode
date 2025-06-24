class Solution {
public:
	int canBeTypedWords(string text, string brokenLetters) {
		vector<string> words = getTokens(text, ' ');
		string& blc = brokenLetters;
		int res = 0;
		for (string w : words) {
			if (find_first_of(w.begin(), w.end(), blc.begin(), blc.end()) == w.end()) res++;
		}
		return res;
	}
private:
	vector<string> getTokens(string& str, char delim)
	{
		stringstream ss(str);
		vector<string> tokens;
		string token;
		ss.clear(); ss.seekg(0);
		while (getline(ss, token, ' ')) tokens.push_back(token);
		return tokens;
	}
};