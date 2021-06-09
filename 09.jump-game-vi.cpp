class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        auto NumberOfElements = nums.size();
        vector<int> MaxSumStartingAt(NumberOfElements);
        priority_queue<pair<int, int>> q;
        MaxSumStartingAt.back() = nums.back();
        q.emplace(make_pair(nums.back(), NumberOfElements - 1));
        
        for (int i = NumberOfElements - 2; i >= 0; --i)
        {
            auto maxSum = q.top();
            auto maxSumIndex = maxSum.second;
            while (maxSumIndex > i + k)
            {
                q.pop();
                maxSum = q.top();
                maxSumIndex = maxSum.second;
            }

            auto maxSumValue = maxSum.first;
            MaxSumStartingAt[i] = nums[i] + maxSumValue;
            q.emplace(make_pair(MaxSumStartingAt[i], i));
        }
        return MaxSumStartingAt[0];
    }
};
