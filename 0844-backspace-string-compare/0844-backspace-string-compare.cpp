class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for (int i = 0; i < s.length(); i++) {
            if (st1.empty() && s[i] == '#') {
                continue;
            } else if (s[i] == '#') {
                st1.pop();
            } else {
                st1.push(s[i]);
            }
        }
        for (int i = 0; i < t.length(); i++) {
            if (st2.empty() && t[i] == '#') {
                continue;
            } else if (t[i] == '#') {
                st2.pop();
            } else {
                st2.push(t[i]);
            }
        }
        
        while(!st1.empty() && !st2.empty()){
            if(st1.top() != st2.top()){
                return false;
            }else{
                st1.pop();
                st2.pop();
            }
        }
        return (st1.empty() && st2.empty()) ? true : false;

    }
};