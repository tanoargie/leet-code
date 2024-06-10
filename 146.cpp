class LRUCache {
private:
  // doubly-linked-list with pair<key, value>. back is the least used.
  list<pair<int, int>> uses;
  // key -> position in uses
  unordered_map<int, list<pair<int, int>>::iterator> values;
  int max;

public:
  LRUCache(int capacity) { this->max = capacity; }

  int get(int key) {
    unordered_map<int, list<pair<int, int>>::iterator>::iterator it =
        this->values.find(key);
    if (it != this->values.end()) {
      int res = (*(it->second)).second;
      this->uses.erase(it->second);
      this->uses.push_front(make_pair(key, res));
      this->values[key] = this->uses.begin();
      return res;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    unordered_map<int, list<pair<int, int>>::iterator>::iterator it =
        this->values.find(key);
    if (it != this->values.end()) {
      this->uses.erase(it->second);
      this->uses.push_front(make_pair(key, value));
      it->second = this->uses.begin();
    } else {
      if (this->values.size() == this->max) {
        pair<int, int> leastUsed = this->uses.back();
        this->uses.pop_back();
        this->values.erase(leastUsed.first);
      }
      this->uses.push_front(make_pair(key, value));
      this->values[key] = this->uses.begin();
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
