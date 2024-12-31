class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> matchingBrackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char ch : s) {
            // If the character is a closing bracket
            if (matchingBrackets.count(ch)) {
                // Check if the stack is not empty and the top matches the corresponding opening bracket
                if (!stack.empty() && stack.top() == matchingBrackets[ch]) {
                    stack.pop(); // Pop the matched opening bracket
                } else {
                    return false; // Mismatched or unbalanced brackets
                }
            } else {
                // If it's an opening bracket, push it onto the stack
                stack.push(ch);
            }
        }

        // If the stack is empty, all brackets were matched
        return stack.empty();
    }
};