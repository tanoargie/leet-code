class Solution {
public:
  vector<int> closestPrimes(int left, int right) {
    vector<int> res(2, -1);
    vector<bool> prime(right + 1, true);
    prime[1] = false;
    for (int i = 2; i * i <= right; i++) {
      if (prime[i] == true) {
        for (int j = i * i; j <= right; j += i) {
          prime[j] = false;
        }
      }
    }
    int min = right - left + 1;
    while (prime[left] == false)
      left++;
    int i = left + 1;
    while (i <= right) {
      if (prime[i] == true) {
        if (i - left < min) {
          min = i - left;
          res[0] = left;
          res[1] = i;
        }
        left = i;
      }
      i++;
    }
    return res;
  }
};
