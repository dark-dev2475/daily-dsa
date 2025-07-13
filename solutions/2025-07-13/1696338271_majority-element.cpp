class Solution {
public:
    int majorityElement(vector<int>& nums) {
    // moore voting algorithm.
    int count=0;
    int cand=nums[0];
    for(int i=0;i<nums.size();i++)
    {
         if(count==0) cand=nums[i];
          if(nums[i]==cand)
          {
            count++;
          }
          else {
            count--;
          }
    }
    return cand;
    }
};