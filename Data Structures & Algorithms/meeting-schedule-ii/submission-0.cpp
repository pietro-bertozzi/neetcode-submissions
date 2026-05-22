/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> diffRooms;
        for (auto& i : intervals) {
            diffRooms[i.start]++;
            diffRooms[i.end]--;
        }
        int prev = 0, result = 0;
        for (auto& [key, value] : diffRooms) {
            prev += value;
            result = max(prev, result);
        }
        return result;
    }
};