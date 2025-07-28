class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxCount = 0;
        int maxNum = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxNum |= nums[i];
        }

        int n = nums.size();
        int total = 1 << n;

        for (int mask = 0; mask < total; ++mask) {
            int temp = 0;
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) {
                    temp |= nums[j];
                }
            }
            if (temp == maxNum) {
                maxCount++;
            }
        }

        return maxCount;
    }
};
