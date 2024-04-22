class Solution {
public:
  int hIndex(vector<int> &citations) {
    int max = 0;
    vector<int> occurrencesAtLeast(1001, 0);
    for (int i = 0; i < citations.size(); i++) {
      occurrencesAtLeast[citations[i]]++;
    }
    for (int i = occurrencesAtLeast.size() - 2; i >= 0; i--) {
      occurrencesAtLeast[i] = occurrencesAtLeast[i] + occurrencesAtLeast[i + 1];
    }
    for (int i = 0; i < occurrencesAtLeast.size(); i++) {
      if (occurrencesAtLeast[i] >= i && i > max) {
        max = i;
      }
    }
    return max;
  }
};
