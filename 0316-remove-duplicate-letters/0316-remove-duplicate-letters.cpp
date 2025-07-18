class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<bool> taken(26, false);
        vector<int> lastSeen(26);

        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;
        };

        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (taken[s[i] - 'a'] == true) {
                continue;
            }
            while (!st.empty() && st.top() > s[i] &&
                   lastSeen[st.top() - 'a'] > i) {
                taken[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            taken[st.top() - 'a'] = true;
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin() , res.end());
        return res;
    }
};