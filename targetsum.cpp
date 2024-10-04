int findTargetSumWays(vector<int>& nums, int diff) {
        int sum = 0;
        int n = nums.size();
        
        // Calculate the total sum of the array
        for (int i : nums) sum += i;

        // Calculate the target sum based on the given difference
        int target = (sum + diff);
        
        // Check if target is valid
        if (target % 2 != 0 || target < 0) {
            return 0;  // No valid solutions
        }
        
        target /= 2;  // We want to find subsets that sum up to target
        
        // Initialize the dp array
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;  // Base case: one way to sum up to 0

        // Fill the dp array
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Return the number of ways to achieve the target sum
        return dp[n][target];
    }
