class Solution {
public:
  bool isValid(string s) {
    stack<char> history;
    char lastOpen;
    bool res = true;
    for (int i = 0; res && i < s.size(); i++) {
      switch (s[i]) {
      case '(':
        history.push('(');
        break;
      case ')':
        if (history.empty()) {
          res = false;
          break;
        }
        lastOpen = history.top();
        history.pop();
        if (lastOpen != '(') {
          res = false;
        }
        break;
      case '[':
        history.push('[');
        break;
      case ']':
        if (history.empty()) {
          res = false;
          break;
        }
        lastOpen = history.top();
        history.pop();
        if (lastOpen != '[') {
          res = false;
        }
        break;
      case '{':
        history.push('{');
        break;
      case '}':
        if (history.empty()) {
          res = false;
          break;
        }
        lastOpen = history.top();
        history.pop();
        if (lastOpen != '{') {
          res = false;
        }
        break;
      }
    }

    return res && history.size() == 0;
  }
};
