class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) { 
            return false;
        }

        int openBrackets = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || locked[i] == '0') {
                ++openBrackets;
            } 
            else if (openBrackets > 0) {
                --openBrackets;
            } 
            else {
                return false;
            }
        }

        int closeBrackets = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || locked[i] == '0') {
                ++closeBrackets;
            } 
            else if (closeBrackets > 0) {
                --closeBrackets;
            } 
            else {
                return false;
            }
        }

        return true;
    }
};
