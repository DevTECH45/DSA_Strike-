class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int n : nums) {
            int digits = 0;
            do {
                digits++;
                n /= 10;
            } while (n != 0);
            if (digits % 2 == 0) count++;
        }
        return count;
    }
};