class Solution {
public:
    void findSubIP(string s, int dots, vector<string>& res, int start, string temp) {
        if (dots == 0 && start == s.length()) {
            res.push_back(temp.substr(0, temp.size() - 1));
        }
        if (dots < 0 || start >= s.length()) return;

        for (int len = 1; len <= 3 && start + len <= s.length(); len++) {
            string part = s.substr(start, len);
            if ((part[0] == '0' && part.length() > 1) || stoi(part) > 255) continue;

            findSubIP(s, dots - 1, res, start + len, temp + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() < 4 || s.length() > 12) return res;
        findSubIP(s, 4, res, 0, "");
        return res;
    }
};
