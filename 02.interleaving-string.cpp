class Solution {
public:
     bool solve(string s1, string s2, string s3, vector < vector < vector <int>>>& dp, int i, int j, int k){
      if(i ==0 && j == 0 && k == 0)return true;
      if(dp[i][j][k] !=-1)return dp[i][j][k];
      bool ans = false;
      if(i > 0 && k >= 0 && s1[i] == s3[k]){
         ans = solve(s1, s2, s3, dp, i - 1, j, k - 1);
      }
      if(j >0 && k >=0 && s2[j] == s3[k]){
         ans |= solve(s1, s2, s3, dp, i, j - 1, k - 1);
      }
      return dp[i][j][k] = ans;
   }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
      int m = s2.size();
      int o = s3.size();
      s1 = " " + s1;
      s2 = " " + s2;
      s3 = " " + s3;
      vector < vector < vector <int>>> dp(n + 1, vector < vector <int>>(m + 1, vector <int> (o + 1, -1)));
      return solve(s1, s2, s3, dp, n , m , o );
    }
};
