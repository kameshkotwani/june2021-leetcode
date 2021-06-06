class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(!n) return 0;
        int count=0;
        unordered_set<int> S(nums.begin(),nums.end());
       for (int i = 0; i < n; i++)
    {
        if (S.find(nums[i] - 1) == S.end())
        {
           
            int j = nums[i];
            while (S.find(j) != S.end())
                j++;
 
            count = max(count, j - nums[i]);
        }
    }
         return count;
    }
   
};
