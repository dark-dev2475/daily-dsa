class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
         
      long long ans=INT_MIN;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+nums[i];
        ans=max(ans,sum);
        if(sum<0)
        {
            sum=0;
        }

    }
      return ans; 
}
  
    
};