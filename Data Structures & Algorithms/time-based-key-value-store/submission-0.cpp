class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> tm;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector lk = tm[key];
        pair<string, int> best = {"", 0};
        int l = 0, r = lk.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (lk[m].second <= timestamp) {
                best = lk[m];
                l = m + 1;
            } else r = m - 1;
        }
        return best.first;
    }
};