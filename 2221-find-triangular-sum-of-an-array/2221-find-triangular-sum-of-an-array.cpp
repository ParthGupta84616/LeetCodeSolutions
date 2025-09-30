class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while (n > 1) {
            vector<int> res;
            for (int i = 0; i < nums.size() - 1; i++) {
                int bag = nums[i] + nums[i + 1];
                res.push_back(bag % 10);
            }
            nums = res;
            n--;
        }
        return nums[0];
    }
};