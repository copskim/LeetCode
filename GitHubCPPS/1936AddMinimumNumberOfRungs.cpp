class Solution {
public:
	constexpr int rsadded(const int& a, const int& b, int d) {
		if (b - a > d) {
			if (d == 1) return (b - a) / d - 1;
			return max(0, (b - a + d - 1) / d - 1);
		}
		return 0;
	}
	int addRungs(vector<int>& rungs, int dist) {
		int n = rungs.size();
		int radds = 0;
		int ra = 0;
		if ((ra = rsadded(0, rungs[0], dist))) radds += ra;
		for (int i = 0; i < n - 1; i++) {
			if ((ra = rsadded(rungs[i], rungs[i + 1], dist))) radds += ra;
		}
		return radds;
	}
};