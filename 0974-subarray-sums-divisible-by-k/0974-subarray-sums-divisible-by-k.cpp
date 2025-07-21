class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp[((sum % k) + k) % k] == 0) {
                mp[((sum % k) + k) % k] += 1;
            } else {
                res += mp[((sum % k) + k) % k];
                mp[((sum % k) + k) % k] += 1;
            }
        }
        return res;
    }
};