class Solution {
public:
// int f(int ans,int ind,int ind1,vector<int> &nums)
// {
//     if(ind1==nums.size()-1) return ans ;
//     if(nums[ind+1]>nums[ind])
//     {
//      return   ans=max(ans,  f(ans,ind,ind1+1,nums));
//     }
//      return max(ans,f(ans,ind1+1,ind1+2,nums));
// } 
    int findLengthOfLCIS(vector<int>& nums) {
        int len=1;
        int ans=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]<nums[i])
            {
                len++;
                ans=max(ans,len);
            }
            else{
                
                len=1;
            }
        } 
        return ans;
    
    }
};