class Solution {
public:
	string addBinary(string a, string b) {
		int rl = max(a.size(), b.size()) + 1;
		string r(rl, '0');
		int al = a.size(); int bl = b.size();
		int ai = al - 1; int bi = bl - 1;
		int carry = 0;
		for (int i = rl - 1; i >= 0; i--) {
			int av, bv;
			if (ai >= 0) av = a[ai] - '0'; else av = 0;
			if (bi >= 0) bv = b[bi] - '0'; else bv = 0;
			if (av + bv == 2) {
				if (carry) r[i] = 1 + '0';
				else carry = 1;
			}
			else if (av + bv == 1) {
				if (carry) r[i] = 0 + '0';
				else r[i] = 1 + '0';
			}
			else {
				if (carry) { r[i] = 1 + '0'; carry = 0; }
			}
			ai--; bi--;
		}
		if (r[0] == '0') return r.substr(1, r.size() - 1);
		return r;
	}
};