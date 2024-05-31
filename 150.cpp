class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<string> st;
    for (auto token : tokens) {
      if (token == "/") {
        string operand1 = st.top();
        st.pop();
        string operand2 = st.top();
        st.pop();
        int result = std::stoi(operand2) / std::stoi(operand1);
        st.push(to_string(result));
      } else if (token == "+") {
        string operand1 = st.top();
        st.pop();
        string operand2 = st.top();
        st.pop();
        int result = std::stoi(operand2) + std::stoi(operand1);
        st.push(to_string(result));
      } else if (token == "*") {
        string operand1 = st.top();
        st.pop();
        string operand2 = st.top();
        st.pop();
        int result = std::stoi(operand2) * std::stoi(operand1);
        st.push(to_string(result));
      } else if (token == "-") {
        string operand1 = st.top();
        st.pop();
        string operand2 = st.top();
        st.pop();
        int result = std::stoi(operand2) - std::stoi(operand1);
        st.push(to_string(result));
      } else {
        st.push(token);
      }
    }
    return std::stoi(st.top());
  }
};
