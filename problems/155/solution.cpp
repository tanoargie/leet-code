class MinStack {
private:
  stack<pair<int, int>> st;

public:
  MinStack() {}

  void push(int val) {
    pair<int, int> newPair = make_pair(val, val);
    if (!st.empty()) {
      int currentMin = getMin();
      if (currentMin < val) {
        newPair = make_pair(val, currentMin);
      }
    }
    st.push(newPair);
  }

  void pop() { st.pop(); }

  int top() { return st.top().first; }

  int getMin() {
    int top = st.top().second;
    return top;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
