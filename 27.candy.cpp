class Solution {
public:
    int candy(vector<int>& ratings) {
     int n=ratings.size();
        vector<int> dp (n,1);
        int ret=0;
        for(int i=1;i<n;i++){
          if(ratings.at(i)>ratings.at(i-1)){
              dp.at(i)=dp.at(i-1)+1;
          }  
        }
        for(int i=n-2;i>=0;i--){
            if(ratings.at(i)>ratings.at(i+1)){
                dp.at(i)=max(dp.at(i),dp.at(i+1)+1);
            }
        }
        ret = accumulate(dp.begin(),dp.end(),ret);
        return ret;
    }
};
