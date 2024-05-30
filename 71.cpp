class Solution {
public:
  string simplifyPath(string path) {
    string res;
    queue<string> operations;
    string partial;
    int i = 0;
    while (i < path.size()) {
      while (i < path.size() && path[i] != '/') {
        partial += path[i];
        i++;
      }
      if (!partial.empty()) {
        operations.push(partial);
        partial.clear();
      }
      string str(1, '/');
      operations.push(str);
      i++;
    }
    while (!operations.empty()) {
      string next = operations.front();
      if (next == "/") {
        if (res.empty() || res.back() != '/') {
          res += next;
        }
      } else if (next == "..") {
        int i = res.size() - 2;
        while (i >= 0 && res[i] != '/') {
          i--;
        }
        if (i >= 0) {
          res.erase(i);
        }
      } else if (next == ".") {

      } else {
        res += next;
      }
      operations.pop();
    }
    if (res.size() > 1 && res[res.size() - 1] == '/') {
      res.pop_back();
    }

    return res;
  }
};
