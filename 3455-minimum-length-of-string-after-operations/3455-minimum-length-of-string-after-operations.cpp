class Solution {
 public:
  int minimumLength(string str) {
    int result = 0;
    vector<int> frequency(26);

    for (const char ch : str)
      ++frequency[ch - 'a'];

    for (int index = 0; index < 26; ++index)
      if (frequency[index] > 0)
        result += frequency[index] % 2 == 0 ? 2 : 1;

    return result;
  }
};
