class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        bool start = true;
        string newV1 = "";
        vector<string> v1;
        vector<string> v2;

        for (int i = 0; i < n1; i++) {
            if (start && version1[i] == '0') {
                continue;
            }
            if (version1[i] == '.') {
                start = true;
                if (newV1 != "")
                    v1.push_back(newV1);
                else
                    v1.push_back("0");
                newV1 = "";
                continue;
            }
            start = false;
            newV1.push_back(version1[i]);
        }
        if (newV1 != "")
            v1.push_back(newV1);
        else
            v1.push_back("0");
        newV1 = "";

        start = true;

        for (int i = 0; i < n2; i++) {
            if (start && version2[i] == '0') {
                continue;
            }
            if (version2[i] == '.') {
                start = true;
                if (newV1 != "")
                    v2.push_back(newV1);
                else
                    v2.push_back("0");
                newV1 = "";
                continue;
            }
            start = false;
            newV1.push_back(version2[i]);
            if (newV1.size() > i) {
                if (newV1[i] < version2[i])
                    return -1;
            }
        }
        if (newV1 != "")
            v2.push_back(newV1);
        else
            v2.push_back("0");

        while (v1.size() < v2.size())
            v1.push_back("0");
        while (v2.size() < v1.size())
            v2.push_back("0");

        for (int i = 0; i < v1.size(); i++) {
            if (stoi(v1[i]) > stoi(v2[i]))
                return 1;
            if (stoi(v1[i]) < stoi(v2[i]))
                return -1;
        }
        return 0;
    }
};
