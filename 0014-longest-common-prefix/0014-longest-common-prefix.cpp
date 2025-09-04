class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string matched = "";
        int counter = 0;
        for (int i = 0; i < strs[0].size(); i++) {
            char nextStr = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != nextStr) {
                    return matched;
                }
            }
            matched += nextStr;
        }
        return matched;
    }
};