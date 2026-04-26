class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r = 0, l = numbers.size() - 1;
        while (r <= l) {
            int offset = numbers[r] + numbers[l] - target;
            if (offset > 0) l--;
            else if (offset < 0) r++;
            else return {r + 1, l + 1};
        }
    }
};
