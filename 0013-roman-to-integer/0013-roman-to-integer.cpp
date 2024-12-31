class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, 
            {'X', 10}, {'V', 5}, {'I', 1}
        };

        int ans = 0;
        int prevValue = 0;

        for (char ch : s) {
            int currentValue = romanMap[ch];

            // If the current value is greater than the previous value,
            // we have encountered a subtraction case
            if (currentValue > prevValue) {
                ans += currentValue - 2 * prevValue; // Remove the added previous value twice
            } else {
                ans += currentValue;
            }

            // Update the previous value for the next iteration
            prevValue = currentValue;
        }

        return ans;
    }
};
