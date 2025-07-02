class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> nextIndex(n, -1); // To reconstruct path

        int maxLen = 1;
        int startIndex = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] < nums[j] && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    nextIndex[i] = j; // remember where to go next
                }
            }
            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
                startIndex = i;
            }
        }

        // Print the LIS
        cout << "Longest Increasing Subsequence: ";
        while (startIndex != -1)
        {
            cout << nums[startIndex] << " ";
            startIndex = nextIndex[startIndex];
        }
        cout << endl;

        return maxLen;
    }
};
