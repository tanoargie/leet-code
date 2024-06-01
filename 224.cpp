class Solution {
public:
  int calculate(string s) {
    int res = 0;
    stack<pair<int, int>> st;
    int sign = 1;
    for (int i = 0; i < s.size(); i++) {
      if (isdigit(s[i])) {
        int num = 0;
        while (i < s.size() && isdigit(s[i])) {
          num = num * 10 + (s[i] - '0');
          i++;
        }
        i--;
        res += num * sign;
        sign = 1;
      } else if (s[i] == '(') {
        st.push({res, sign});
        res = 0;
        sign = 1;
      } else if (s[i] == ')') {
        pair<int, int> group = st.top();
        st.pop();
        res = group.first + (sign * res * group.second);
      } else if (s[i] == '-') {
        sign = (-1) * sign;
      }
    }

    return res;
  }
};
