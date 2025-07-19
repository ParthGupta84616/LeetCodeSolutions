class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;

        string baseString = folder[0];
        res.push_back(baseString);
        baseString += '/';
        for (int i = 1; i < folder.size(); i++) {
            int len = baseString.length();
            while (len--) {
                if (folder[i].length() >= len &&
                    baseString[len] == folder[i][len]) {
                    continue;
                } else {
                    res.push_back(folder[i]);
                    baseString = folder[i] + '/';
                    break;
                }
            }
        }
        return res;
    }
};