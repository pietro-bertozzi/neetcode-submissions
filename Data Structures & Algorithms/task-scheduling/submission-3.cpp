class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> occurrences(26, 0);
        for (char task : tasks) occurrences[task - 'A']++;
        int best = *max_element(occurrences.begin(), occurrences.end());
        int bests = count(occurrences.begin(), occurrences.end(), best);
        int time = (best - 1) * (n + 1) + bests;
        return max((int)tasks.size(), time);
    }
};