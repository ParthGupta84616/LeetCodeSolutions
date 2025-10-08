class Solution {
public:
    int binarySearch(const vector<int>& potions, long long value) {
        int start = 0;
        int end = potions.size() - 1;
        int res = potions.size();
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (potions[mid] >= value) {
                res = mid;
                end = mid - 1;

            } else {
                start = mid + 1;
            }
        }
        return res;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (int i = 0; i < spells.size(); i++) {
            long long toFind = (success + spells[i] - 1) / spells[i];
            int found = potions.size() - binarySearch(potions, toFind);
            res.push_back(found);
        }
        return res;
    }
};