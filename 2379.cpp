class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    vector<string> substrings;
    for (int i = 0; i + k <= blocks.size(); i++) {
      substrings.push_back(blocks.substr(i, k));
    }

    int min = blocks.size();
    for (int i = 0; i < substrings.size(); i++) {
      int counter = 0;
      for (int j = 0; j < substrings[i].size(); j++) {
        if (substrings[i][j] == 'W')
          counter++;
      }
      if (min > counter)
        min = counter;
    }
    return min;
  }
};
