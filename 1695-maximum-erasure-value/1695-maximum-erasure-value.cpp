class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        int lptr = 0;
        int rptr = 0;
        int sum = 0;
        int res = 0;
        while (rptr < n && lptr <= rptr) {
            if (mp[nums[rptr]] == 0) {
                sum += nums[rptr];
                mp[nums[rptr]]++;
                rptr++;
            } else {
                res = max(res, sum);
                while (mp[nums[rptr]] > 0) {
                    mp[nums[lptr]]--;
                    sum -= nums[lptr];
                    lptr++;
                }
            }
        }
        res = max(res, sum);
        return res;
    }
};