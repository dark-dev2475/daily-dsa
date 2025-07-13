class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      
        int n= nums.size();
        // int candidate;
        int pos=0;
        int neg=1;
        vector<int> result(n);

         for(int i:nums)
         {
            if(i>=0)
            {
              result[pos]=i;
              pos+=2;
            }
            else{
                result[neg]=i;
                neg+=2;
            }
         }
         return result;
        
    }
};