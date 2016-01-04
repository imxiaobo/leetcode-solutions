class LRUCache {
  list<pair<int, int>> _lru;
  unordered_map<int, list<pair<int, int>>::iterator> _lookup;
  int _capacity;

public:
  LRUCache(int capacity) : _capacity(capacity) {}

  int get(int key) {

    // find in lookup hashmap
    auto found = _lookup.find(key);

    // not found
    if (found == _lookup.end())
      return -1;

    // move to head
    _lru.splice(_lru.begin(), _lru, found->second);

    // record in lookup hashmap
    _lookup[key] = _lru.begin();

    // return value
    return _lru.front().second;
  }

  void set(int key, int value) {
    // lookup
    auto found = _lookup.find(key);

    // found key
    if (found != _lookup.end()) {
      // set value
      found->second->second = value;
      // move to head
      _lru.splice(_lru.begin(), _lru, found->second);
    }
    // not found
    else {
      // insert
      _lru.emplace_front(key, value);
      _lookup[key] = _lru.begin();

      // remove lru
      if (_lookup.size() > _capacity) {
        _lookup.erase(_lru.back().first);
        _lru.pop_back();
      }
    }
  }
};
