class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> vec(value, 0);
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int mod = (nums[i] % value + value) % value;
            vec[mod]++;
        }
        while (vec[res % value]--) res++;
		return res;
    }
};