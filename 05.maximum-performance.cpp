class Solution {
public:
    const long long int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long int res = 0;
        auto& s=speed;
        auto& e =efficiency;
        vector<vector<int>> v;
        for (int i=0;i<n;i++){
            v.push_back({e[i],s[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long int sum=0;
        for(int i=0;i<n;i++){
            if(pq.size()==k){
                sum-=pq.top();
                pq.pop();
            }
            sum+=v[i][1];
            pq.push(v[i][1]);
            res = max(res,sum*v[i][0]);
            
        }
      return res % (long long int)(1e9 + 7);
    }
};
