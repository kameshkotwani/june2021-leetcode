class Solution {
public:
    bool solve(int index,vector<int>& sums,int target,vector<int>& nums)
    {
        bool ans=false;
        if(index >=nums.size()){
            if(sums[0] == sums[1] and sums[1] == sums[2] and sums[2] == target){
                ans=true;
                return ans;
            }
            
        }
            for(int i=0;i<4;i++){
                if(sums[i]+nums[index]>target) continue;
                sums[i]+=nums[index];
                if(solve(index+1,sums,target,nums)) return true;
                sums[i]-=nums[index];
            
        }
        return ans;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        auto& nums=matchsticks;
        int n=nums.size();   
        if(!n) return false;
        int x=0;
        for(int i=0;i<n;i++) x+=nums[i];
        if(x%4) return false;
       sort(nums.rbegin(),nums.rend());
        vector<int> sums(4);
        return solve(0,sums,x/4,nums);
    }
};
