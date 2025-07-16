class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> res;
        vector<string> resS;

        int temp = 0, start = 0;
        for (int i = 0; i < words.size(); i++) {
            if (temp + words[i].length() <= maxWidth) {
                if (temp + words[i].length() == maxWidth) {
                    temp += words[i].length();
                } else {
                    temp += words[i].length() + 1;
                }
            } else {
                res.push_back(i - 1);
                temp = words[i].length() + 1;
            }
        }

        if (temp) {
            res.push_back(words.size() - 1);
        }

        int idx = 0;
        for (int i = 0; i < words.size();) {
            int end = res[idx];
            string tempStr = "";
            int totalLength = 0;
            for (int j = i; j <= end; ++j) {
                totalLength += words[j].length();
            }
            int totalSpace = maxWidth - totalLength;
            int numWords = end - i + 1;
            int gaps = numWords - 1;

            if (idx == res.size() - 1 || gaps == 0) {
                for (int j = i; j <= end; ++j) {
                    tempStr += words[j];
                    if (j != end) tempStr += " ";
                }
                tempStr += string(maxWidth - tempStr.length(), ' ');
            } else {
                int evenSpace = totalSpace / gaps;
                int extraSpace = totalSpace % gaps;
                for (int j = i; j < end; ++j) {
                    tempStr += words[j];
                    tempStr += string(evenSpace + (extraSpace-- > 0 ? 1 : 0), ' ');
                }
                tempStr += words[end];
            }

            resS.push_back(tempStr);
            i = end + 1;
            idx++;
        }

        return resS;
    }
};
