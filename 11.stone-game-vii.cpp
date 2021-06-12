class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
    auto& s=stones;
        int n=s.size();
        vector<int> dpcurr(n),dplast(n);
        for(int i=n-2;~i;i--){
            int total=s[i];
            dplast.swap(dpcurr);
            for(int j=i+1;j<n;j++){
                total+=s[j];
                dpcurr[j]=max(total-s[i]-dplast[j],total-s[j]-dpcurr[j-1]);
            }
        }
        return dpcurr[n-1];
    }
};
