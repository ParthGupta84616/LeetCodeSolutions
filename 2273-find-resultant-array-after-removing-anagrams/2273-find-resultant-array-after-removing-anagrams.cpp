class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string lastWord;
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            string newWord = words[i];
            sort(words[i].begin(), words[i].end());
            if (lastWord != words[i]) {
                lastWord = words[i];
                res.push_back(newWord);
            }
        }
        return res;
    }
};