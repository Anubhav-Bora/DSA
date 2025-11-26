#include <bits/stdc++.h>
using namespace std;

/*class Solution {
public:
int rec(int i,vector<int> &nums,vector<int> &dp){
    if(i>=nums.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    //not_takec
    int not_take=rec(i+1,nums,dp);
    //take
    int take=rec(i+2,nums,dp)+nums[i];
    return dp[i]=max(take,not_take);
}
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return rec(0,nums,dp);
    }
};*/
class Solution
{
public:
    int rec(int i, vector<int> &nums)
    {
        vector<int> dp(nums.size() + 2, 0);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);
        }
        return dp[0];
    }

    int rob(vector<int> &nums)
    {
        return rec(0, nums);
    }
};