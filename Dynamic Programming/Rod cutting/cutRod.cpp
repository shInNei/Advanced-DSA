// Time Complexity: O(n^2)
// Auxiliart Space: O(n)
int cutRod(int price[], int n) {
        //code here
        
        // dp is an array of optimal revenue
        vector<int> dp(n + 1, 0);
        
        /* If we want to calculate the optimal value of n,
         * We must loop from 1 -> n.
         * Then in each value, we simply calculate base on older optimal value
         * == loop ( max(q, price[] + r[]))
        */
        for(int i = 1; i <= n; ++i) {
            int q = INT_MIN;
            for(int j = 0; j < i; ++j) {
                q = max(q, price[j] + dp[i - j - 1]);
            }
            dp[i] = q;
        }
        return dp[n];
    }
