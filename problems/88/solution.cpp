class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int f = 0;
    int s = 0;
    queue<int> rest;
    if (n == 0) {
    } else if (m == 0) {
      nums1 = nums2;
    } else {
      while (f < n + m) {
        // cout << "check"
        // << " " << f << " " << s << endl;
        if (f >= m) {
          // desencolo de la pila o mando nums2 (lo que sea menor)
          if (rest.size() > 0 &&
              ((s < n && rest.front() < nums2[s]) || s >= n)) {
            nums1[f] = rest.front();
            rest.pop();
          } else {
            nums1[f] = nums2[s];
            s++;
          }
        } else {
          if (rest.size() > 0 && s < n && nums2[s] < rest.front()) {
            // hay pila y nums2 es menor al tope
            int pivot = nums1[f];
            rest.push(pivot);
            nums1[f] = nums2[s];
            s++;
          } else if (rest.size() > 0) {
            // hay pila y tope es menor que nums2 o ya no hay mas nums2
            int pivot = nums1[f];
            rest.push(pivot);
            nums1[f] = rest.front();
            rest.pop();
          } else if (nums2[s] < nums1[f]) {
            // no hay pila y nums2 es menor a nums1
            int pivot = nums1[f];
            nums1[f] = nums2[s];
            rest.push(pivot);
            s++;
          }
        }
        f++;
      }
    }
  }
};
