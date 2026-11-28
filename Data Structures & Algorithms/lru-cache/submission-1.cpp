class LRUCache {
   public:
    vector<pair<int, int>> cache;
    unordered_map<int, int> mp;
    int n = 0;
    LRUCache(int capacity) { n = capacity; }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        int v = 0;
        for (int i = 0; i < cache.size(); i++)
            if (cache[i].first == key) {
                v = cache[i].second;
                cache.erase(cache.begin() + i);
                break;
            }
        cache.push_back({key, v});
        return mp[key];
    }

    void put(int key, int value) {
        if (mp.contains(key)) {
            for (int i = 0; i < cache.size(); i++)
                if (cache[i].first == key) {
                    cache.erase(cache.begin() + i);
                    break;
                }
        }
        if (cache.size() == n) {
            mp.erase(cache[0].first);  
            cache.erase(cache.begin());
        }

        cache.push_back({key, value});
        mp[key] = value;
    }
};
