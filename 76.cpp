class Solution {
public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) {
      return "";
    }

    int appearancesT[256] = {0};
    for (int i = 0; i < t.size(); i++) {
      appearancesT[t[i]]++;
    }
    int start = 0;
    int startIndex = -1;
    int min = INT_MAX;
    int count = 0;
    int appearancesS[256] = {0};
    for (int i = 0; i < s.size(); i++) {
      appearancesS[s[i]]++;

      if (appearancesS[s[i]] <= appearancesT[s[i]]) {
        count++;
      }
      // cout << count << endl;

      if (count == t.size()) {
        // cout << "test:" << start << " " << i << endl;
        while (appearancesS[s[start]] > appearancesT[s[start]] ||
               appearancesT[s[start]] == 0) {
          if (appearancesS[s[start]] > appearancesT[s[start]]) {
            appearancesS[s[start]]--;
          }
          start++;
        }
        // cout << "test2:" << start << " " << i << endl;

        if (min > i - start + 1) {
          min = i - start + 1;
          startIndex = start;
        }
      }
    }

    if (startIndex == -1) {
      return "";
    }

    return s.substr(startIndex, min);
  }
};
