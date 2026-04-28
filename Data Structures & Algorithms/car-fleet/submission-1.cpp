class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (!n) return 0;
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return position[i] > position[j];
        });
        int fleets = 0;
        double max_time = -1.0;
        for (int i = 0; i < n; ++i) {
            double current_time = (double)(target - position[idx[i]]) / speed[idx[i]];
            if (current_time > max_time) {
                max_time = current_time;
                fleets++;
            }
        }
        return fleets;
    }
};