class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        int n= nums.size();
        for(int i:nums)

        {
            if(i>0)
            {
                positive.push_back(i);
            }
            if(i<0)
            {
                negative.push_back(i);
            }
        }
        vector<int> nums1(n);
        int posInd=0,negInd=0;
         for(int i=0;i<n;i++)
         {
            if(i%2==0){
            
            nums1[i]=(positive[posInd++]);
            }
            else{
            
            nums1[i]=(negative[negInd++]);
            }


              
         }
         return nums1;

    }
};