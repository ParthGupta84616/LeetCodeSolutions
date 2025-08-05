class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        vector<bool> occupied(m);
        int count = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(baskets[j] >= fruits[i] && !occupied[j]){
                    occupied[j] = true;
                    count -= 1;
                    break;
                }
            }
        }
        return count;
    }
};