class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int window = 2 * k;
        int n = 0;
        while (n <= nums.size() - window) { 
            bool hugdis = false;

            for (int i = 1; i < k; i++) {
                if (nums[n + i] <= nums[n + i - 1]) {
                    hugdis = true;
                    break;
                }
                if (nums[n + k + i] <= nums[n + k + i - 1]) {
                    hugdis = true;
                    break;
                }
            }

            if (hugdis) {
                n++;
                continue;
            }

            return true;  
        }
        return false;
    }
};
