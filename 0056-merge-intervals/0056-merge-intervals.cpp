class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());  // sort by start time

        vector<vector<int>> result;

        for (auto& interval : intervals) {
            // if result is empty or no overlap, just append
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            } else {
                // overlap — extend the end if needed
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};