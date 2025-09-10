class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        queue<pair<string, int>> pq;
        pq.push({beginWord, 1});

        while (!pq.empty()) {
            int tryCount = pq.front().second;
            string originalWord = pq.front().first;
            pq.pop();
            for (int j = 0; j < originalWord.size(); j++) {
                string word = originalWord;
                for (char i = 'a'; i <= 'z'; i++) {
                    word[j] = i;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        pq.push({word , tryCount+1});
                        if(word == endWord){
                            return tryCount + 1;
                        };
                    }
                }
            }
        }
        return 0;
    }
};