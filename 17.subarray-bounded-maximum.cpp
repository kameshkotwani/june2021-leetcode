class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        auto& A =nums;   
        int L=left;
        int R=right;
        int ret = 0;
      int dp = 0;
      int prev = -1;
      for(int i = 0; i < A.size(); i++){
         if(A[i] < L && i > 0){
            ret += dp;
         }
         if(A[i] > R){
            prev = i;
            dp = 0;
         }
         else if(A[i] >= L && A[i] <= R){
            dp = i - prev;
            ret += dp;
         }
      }
      return ret;
   }
    
};
