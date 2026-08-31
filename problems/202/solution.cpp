class Solution {
public:
  int myPow(int x, unsigned int p) {
    if (p == 0)
      return 1;
    if (p == 1)
      return x;

    int tmp = myPow(x, p / 2);
    if (p % 2 == 0)
      return tmp * tmp;
    else
      return x * tmp * tmp;
  }

  bool recursiveIsHappy(int n, unordered_set<int> &seen) {
    if (seen.find(n) != seen.end()) {
      return false;
    }
    seen.insert(n);
    vector<int> digits;
    while (n >= 10) {
      digits.push_back(n % 10);
      n /= 10;
    }
    digits.push_back(n);
    int sum = 0;
    for (auto digit : digits) {
      sum += myPow(digit, 2);
    }
    if (sum == 1) {
      return true;
    }
    return recursiveIsHappy(sum, seen);
  }

  bool isHappy(int n) {
    unordered_set<int> pastSeen;
    return recursiveIsHappy(n, pastSeen);
  }
};
