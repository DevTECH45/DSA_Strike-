class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: count frequencies
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        // Step 2: bucket sort — index = frequency, max freq = n
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto& [num, cnt] : freq)
            buckets[cnt].push_back(num);

        // Step 3: collect top-k scanning right to left
        vector<int> result;
        for (int i = n; i >= 1 && (int)result.size() < k; i--)
            for (int v : buckets[i])
                result.push_back(v);

        return result;
    }
};