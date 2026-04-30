class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        unordered_map<int, int> count;
        for (int h : hand) count[h]++;
        for (int h : hand) {
            int start = h;
            while (count[start--]) {}
            start++;
            while (start <= h) {
                while (count[start] > 0) {
                    for (int i = start; i < start + groupSize; ++i) {
                        if (count[i]-- <= 0) return false;
                    }
                }
                start++;
            }
        }
        return true;
    }
};