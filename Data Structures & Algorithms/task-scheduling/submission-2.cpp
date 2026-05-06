class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) count[task - 'A']++;
        sort(count.begin(), count.end());
        int best = count[25];
        int idle = (best - 1) * n;
        for (int i = 24; i >= 0; i--) idle -= min(best - 1, count[i]);
        return tasks.size() + (idle > 0 ? idle : 0);
    }
};