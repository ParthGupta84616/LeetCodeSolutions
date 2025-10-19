class Solution {
public:
    int partitionString(string s) {
        set<int> st;
        int res = 1;
        for (auto ch : s) {
            if (st.find(ch) != st.end()) {
                st.clear();
                st.insert(ch);
                res++;
            }
            st.insert(ch);
        }
        return res;
    }
};