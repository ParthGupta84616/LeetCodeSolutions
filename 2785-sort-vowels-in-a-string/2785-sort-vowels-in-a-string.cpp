class Solution {
public:
    string sortVowels(string s) {
        priority_queue<char, vector<char>, greater<char>> heap;
        vector<int> index;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
                s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || 
                s[i] == 'o' || s[i] == 'u') {
                heap.push(s[i]);
                index.push_back(i);
            }
        }
        for (int x : index) {
            s[x] = heap.top();
            heap.pop();
        }
        return s;
    }
};
