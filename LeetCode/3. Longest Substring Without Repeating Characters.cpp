class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> latestIndex(128, -1);
		int start = 0, longest = 0;
		for (int i = 0; i<s.length(); i++)
		{
			start = max(start, latestIndex[s[i]] + 1);
			latestIndex[s[i]] = i;
			longest = max(longest, i - start + 1);
		}
		return longest;
	}
};