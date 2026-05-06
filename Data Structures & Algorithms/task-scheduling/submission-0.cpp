class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char t : tasks) count[t - 'A']++;
        priority_queue<int> maxHeap;
        for (int c : count) if (c) maxHeap.push(c);
        int time = 0;
        queue<pair<int, int>> q;
        while (!maxHeap.empty() || !q.empty()) {
            time++;
            if (maxHeap.empty()) time = q.front().second;
            else {
                int c = maxHeap.top() - 1;
                maxHeap.pop();
                if (c) q.push({c, time + n});
            }
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};