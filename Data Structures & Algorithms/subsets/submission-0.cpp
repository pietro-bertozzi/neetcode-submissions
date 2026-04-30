class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        for (int n : nums) {
            int s = result.size();
            for (int i = 0; i < s; ++i) {
                result.push_back(result[i]);
                result.back().push_back(n);
            }
        }
        return result;
    }
};
