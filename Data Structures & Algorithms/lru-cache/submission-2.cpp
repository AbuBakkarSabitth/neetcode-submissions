class LRUCache {
public:
    int cap;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        auto it = mp[key];
        int val = it->second;

        l.erase(it);
        l.push_front({key, val});
        mp[key] = l.begin();

        return val;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end())
            l.erase(mp[key]);

        l.push_front({key, value});
        mp[key] = l.begin();

        if(l.size() > cap) {
            int k = l.back().first;
            l.pop_back();
            mp.erase(k);
        }
    }
};