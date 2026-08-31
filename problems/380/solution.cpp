class RandomizedSet {
private:
  vector<int> vector;
  unordered_map<int, int> map;

public:
  RandomizedSet() { srand(time(NULL)); }

  bool insert(int val) {
    unordered_map<int, int>::iterator res = this->map.find(val);
    if (res != this->map.end()) {
      // is there, so return false
      return false;
    } else {
      // insert and return true
      this->vector.push_back(val);
      this->map[val] = this->vector.size() - 1;
      return true;
    }
  }

  bool remove(int val) {
    unordered_map<int, int>::iterator res = this->map.find(val);
    if (res != this->map.end()) {
      // is there, so remove it and return true
      if (this->vector.size() > 1) {
        // swap with last and pop
        int oldLastValue = this->vector[this->vector.size() - 1];
        int valPosition = res->second;
        this->vector[this->vector.size() - 1] = val;
        this->vector[valPosition] = oldLastValue;
        this->map[oldLastValue] = valPosition;
      }
      this->vector.pop_back();
      this->map.erase(res);
      return true;
    } else {
      // not there, so return false
      return false;
    }
  }

  int getRandom() {
    int random_pos = rand() % this->vector.size();
    return this->vector[random_pos];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
