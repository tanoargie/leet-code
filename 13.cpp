class Solution {
public:
  int aux(char c) {
    switch (c) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    default:
      return 0;
    }
  }

  int romanToInt(string s) {
    int res = aux(s[0]);
    for (int i = 1; i < s.size(); i++) {
      if (aux(s[i - 1]) < aux(s[i])) {
        // IX, XL
        res -= aux(s[i - 1]);
        res += (aux(s[i]) - aux(s[i - 1]));
      } else {
        res += aux(s[i]);
      }
    }

    return res;
  }
};
