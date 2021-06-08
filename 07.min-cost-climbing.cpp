class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
       int dp1 = 0, dp2 = 0;
    for (int i = 0; i < n; i++) {
        int dp0 = cost[i] + min(dp1, dp2);
        dp2 = dp1;
        dp1 = dp0;
    }
    return min(dp1, dp2);
    }
};
