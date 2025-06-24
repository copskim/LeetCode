class Solution {
public:
	int maxLength(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int n = nums.size();
		int maxL = 2;
		for (int i = 0; i < n; i++) {
			int sublen = subMax(nums, i);
			if (maxL < sublen) maxL = sublen;
		}
		return maxL;
	}
private:
	int subMax(vector<int>& nums, int si)
	{
		int sublen = 0;
		vector<bool> tf(11, false);
		for (int i = si; i < nums.size(); i++) {
			if (nums[i] == 1) sublen++;
			else if (
				((nums[i] == 2) && !(tf[2] || tf[4] || tf[6] || tf[8] || tf[10])) ||
				((nums[i] == 3) && !(tf[3] || tf[6] || tf[9])) ||
				((nums[i] == 4) && !(tf[2] || tf[4] || tf[6] || tf[8] || tf[10])) ||
				((nums[i] == 5) && !(tf[5] || tf[10])) ||
				((nums[i] == 6) && !(tf[2] || tf[4] || tf[6] || tf[8] || tf[10] || tf[3] || tf[9])) ||
				((nums[i] == 7) && !(tf[7])) ||
				((nums[i] == 8) && !(tf[2] || tf[4] || tf[6] || tf[8] || tf[10])) ||
				((nums[i] == 9) && !(tf[3] || tf[6] || tf[9])) ||
				((nums[i] == 10) && !(tf[2] || tf[4] || tf[6] || tf[8] || tf[10] || tf[5]))
				) sublen++;
			else break;
			tf[nums[i]] = true;
		}
		return sublen;
	}
};