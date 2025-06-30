class Solution {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> count;
    for (int num : nums)
      ++count[num];

    int ans = 0;
    for (auto it = count.begin(); it != count.end(); ++it) {
      int curr = it->first;
      if (count.count(curr + 1))
        ans = max(ans, it->second + count[curr + 1]);
    }

    return ans;
  }
};
