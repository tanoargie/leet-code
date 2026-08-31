class Solution {
public:
  bool dfs(int src, int dst, vector<vector<double>> &matrix,
           vector<bool> &visited, double &res) {
    if (src == dst)
      return true;
    visited[src] = true;
    for (int i = 0; i < matrix.size(); i++) {
      if (matrix[src][i] != -1.0 && !visited[i]) {
        if (dfs(i, dst, matrix, visited, res)) {
          res *= matrix[src][i];
          return true;
        }
      }
    }
    return false;
  }
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    vector<double> result;
    unordered_map<string, int> indices;
    vector<vector<double>> matrix(equations.size() * 2,
                                  vector<double>(equations.size() * 2, -1.0));
    int pos = 0;
    for (int i = 0; i < equations.size(); i++) {
      string src = equations[i][0];
      string dst = equations[i][1];
      if (indices.find(src) == indices.end()) {
        indices[src] = pos;
        pos++;
      }
      if (indices.find(dst) == indices.end()) {
        indices[dst] = pos;
        pos++;
      }
      matrix[indices[src]][indices[dst]] = values[i];
      matrix[indices[dst]][indices[src]] = 1 / values[i];
      matrix[indices[dst]][indices[dst]] = 1.0;
      matrix[indices[src]][indices[src]] = 1.0;
    }
    for (int i = 0; i < queries.size(); i++) {
      vector<bool> visited(equations.size() * 2, false);
      double res = 1.0;
      if (indices.find(queries[i][0]) != indices.end() &&
          indices.find(queries[i][1]) != indices.end()) {
        if (dfs(indices[queries[i][0]], indices[queries[i][1]], matrix, visited,
                res)) {
          result.push_back(res);
        } else {
          result.push_back(-1.0);
        }
      } else {
        result.push_back(-1.0);
      }
    }

    return result;
  }
};
