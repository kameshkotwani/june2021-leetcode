class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0,j=0;
        for(int i=0;i<n;i++){
            if(nums.at(i)==0) k--;
            while(j<=i and k<0){
                if(nums.at(j)==0) k++;
                j++;
            }
            ans = max(i-j+1,ans);
        }
        return ans;
    }
};
