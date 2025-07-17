class Solution {
public:
    int maximumLength(vector<int>& nums) {
       int even_count=0,odd_count=0;
       for(int num:nums)
       {
        if(num%2==0) even_count++;
        else odd_count++;

       }
        int even_dp=0;
        int odd_dp=0;
        for(int num:nums)
        {
            if(num%2==0) {
               even_dp=max(even_dp,odd_dp+1);
            }
            else{
                odd_dp=max(even_dp+1,odd_dp);
            }
        }
        return max({even_count,odd_count,even_dp,odd_dp});
    }
};
