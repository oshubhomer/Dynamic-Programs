#include<bits/stdc++.h>
using namespace std;

int countsubstsum(vector<int>& nums, int n, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;  // Sum 0 can always be achieved by selecting no elements
    }

    // Fill the dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int countsubdiff(vector<int> nums, int diff) {
    int sum = 0;
    for (int i : nums) sum += i;

    

    int target = (sum + diff) / 2;
    return countsubstsum(nums, nums.size(), target);
}

int main() {
    vector<int> v = {1, 1, 2, 3};
    cout << countsubdiff(v, 1) << endl;
    return 0;
}
