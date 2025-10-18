class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int res = 0;
        map<int, int> mp;
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        for (auto it : mp) {
            if (it.second == 1)
                return -1;
            if (it.second % 3 != 0) {
                res += 1;
            }
            res += it.second / 3;
        }
        return res;
    }
};