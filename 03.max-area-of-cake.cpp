class Solution {
public:
    typedef long long int LLI;
    const int MOD = 1e9+7;
    LLI mul(LLI a,LLI b){
        return ((a%MOD)*(b%MOD))%MOD;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        auto& hh = horizontalCuts;
        auto& vv = verticalCuts;

        sort(hh.begin(),hh.end()); 
        sort(vv.begin(),vv.end());    
        hh.insert(hh.begin(),0);
        hh.emplace_back(h);
        vv.insert(vv.begin(),0);
        vv.emplace_back(w);
        
        int a=0,b=0;
        for(int i=1;i<hh.size();i++)
            a= max(a,hh[i]-hh[i-1]);
         for(int i=1;i<vv.size();i++)
            b= max(b,vv[i]-vv[i-1]);
        return mul(a,b);

    }
};
