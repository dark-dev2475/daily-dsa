class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int miss;
        vector<int> hash(n+1);
        for(int i:nums)
        {
            hash[i]++;
            if(hash[i]==2) {
                miss=i;
                break;
            }
        }
        return miss;
    }
};