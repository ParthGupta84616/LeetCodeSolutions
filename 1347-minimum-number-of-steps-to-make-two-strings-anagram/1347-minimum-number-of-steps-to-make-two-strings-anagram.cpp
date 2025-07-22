class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> res(26 , 0);
        for(int i = 0 ; i < s.length() ; i++){
            res[s[i] - 'a'] += 1;
            res[t[i] - 'a'] -= 1;
        }
        int count = 0;
        for(int i = 0 ; i < res.size() ; i++){
            count += abs(res[i]);
        }
        return count/2;
    }
};