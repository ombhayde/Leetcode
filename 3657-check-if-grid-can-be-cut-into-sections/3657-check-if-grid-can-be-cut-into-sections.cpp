class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int len = rectangles.size();
        vector<vector<int>> cuts(len, vector<int>(2));
        
        initializeCuts(rectangles, cuts, 1, 3);
        if (isValidCut(cuts)) 
            return true;

        initializeCuts(rectangles, cuts, 0, 2);
        return isValidCut(cuts);
    }

private:
    void initializeCuts(vector<vector<int>>& rectangles, vector<vector<int>>& cuts, int xIdx, int yIdx) {
        int len = rectangles.size();
        for (int i = 0; i < len; i++) {
            cuts[i][0] = rectangles[i][xIdx];
            cuts[i][1] = rectangles[i][yIdx];
        }
    }

    bool isValidCut(vector<vector<int>>& cuts) {
        int n = cuts.size(), x = 0, j = 0;
        
        sort(cuts.begin(), cuts.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) 
                return a[0] < b[0];
            return a[1] > b[1];
        });
        
        while (j < n - 1) {
            int cur = cuts[j][1];
            while (j < n && cuts[j][0] < cur) {
                cur = max(cur, cuts[j][1]);
                j++;
            }
            if (j < n)
                x++;
        }
        
        return x >= 2;
    }
}; 