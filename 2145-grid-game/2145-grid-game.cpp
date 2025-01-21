using ll = long long; // Define 'll' as an alias for 'long long' for simplicity

class Solution {
public:
    long long gridGame(std::vector<std::vector<int>>& grid) {
        // The function to calculate the minimal points the second player can obtain
      
        ll answer = LONG_MAX; // Initialize the answer variable to maximum possible long long value
        int numColumns = grid[0].size(); // Number of columns in the grid
        ll upperSum = 0, lowerSum = 0; // Variables to keep track of the prefix sums of the top and bottom rows

        // Calculate the initial prefix sum of the top row
        for (int value : grid[0]) {
            upperSum += value;
        }

        // Iterate through the grid to find the minimal points the second player will end up with
        for (int columnIndex = 0; columnIndex < numColumns; ++columnIndex) {
            // Decrease the upperSum by the current top grid value since the robot will pass it
            upperSum -= grid[0][columnIndex];

            // Take the maximum of the remaining values in the upperSum and lowerSum, as it's the value the second player is guaranteed to get at least
            // Then take the minimum of this and answer to find the minimum points the second player will have to collect throughout the game
            answer = std::min(answer, std::max(upperSum, lowerSum));

            // Increase the lowerSum by the current bottom grid value as the robot can collect it
            lowerSum += grid[1][columnIndex];
        }

        // Return the final answer which is the minimal points the second player will get
        return answer;
    }
};