class Solution {
public:
    string reverseString(string s) {
        int len_s = s.size();
        int head = 0, tail = s.size() - 1;
        while (head <= tail) swap(s[head++], s[tail--]);
        return s;
    }
};