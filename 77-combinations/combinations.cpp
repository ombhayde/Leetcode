#include <vector>
#include <functional> // For std::function

class Solution {
public:
    // Returns all possible combinations of k numbers out of 1...n
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations; // Stores all the combinations
        vector<int> current; // Stores the current combination

        // Depth-first search (DFS) to find all combinations
        std::function<void(int)> dfs = [&](int start) {
            // If the current combination is of size k, add it to the answers
            if (current.size() == k) {
                combinations.emplace_back(current);
                return;
            }

            // If we've passed the last number, stop the recursion
            if (start > n) {
                return;
            }

            // Include the current number and go deeper
            current.emplace_back(start);
            dfs(start + 1); // Recurse with the next number

            // Exclude the current number and go deeper
            current.pop_back();
            dfs(start + 1); // Recurse with the next number
        };

        // Start the recursion with the first number
        dfs(1);

        // Return all the found combinations
        return combinations;
    }
};
