class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> count;
        for (int h : hand) count[h]++;
        for (int h : hand) {
            if (count[h]) {
                for (int i = h; i < h + groupSize; ++i) {
                    if (count[i]-- <= 0) return false;
                }
            }
        }
        return true;
    }
};