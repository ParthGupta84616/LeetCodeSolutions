class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        for (int i = 0; i < gas.size(); i++) {
            diff.push_back(gas[i] - cost[i]);
        }

        int sum = accumulate(diff.begin(), diff.end(), 0);
        if (sum < 0)
            return -1;

        int start = -1;
        sum = 0;
        for (int i = 0; i < diff.size(); i++) {
            if ((diff[i] >= 0 && (start == -1 || sum < 0))) {
                sum = 0;
                start = i;
            }

            if (start != -1) {
                sum += diff[i];
            }
        }
        return start;
    }
};