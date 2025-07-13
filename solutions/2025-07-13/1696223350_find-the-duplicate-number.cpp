class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
       int low=1;
       int high=n-1;
    //    int ans=0;
       while(low<high)
       {
       int count=0;
       int mid=(low+high)/2;
       for(int i:nums)
       {
        if(i<=mid) count++;
       }
       if(count>mid)
       {
        high=mid;
       }
       else {
        low=mid+1;

       }
       }
       return low;
    }
};
