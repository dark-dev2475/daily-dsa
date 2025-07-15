class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //  int n=nums.size();
        //  int freq1=0;
        //  int freq2=0;
        //   vector<int> ans(2);
        //  for(int i=0;i<n;i++)
        //  {
        //     if(freq1==0&&nums[i]!=ans[1])
        //     {
        //         freq1=1;
        //         ans[0]=nums[i];
        //     }
        //     else if(freq2==0&&nums[i]!=ans[0])
        //     {
        //         freq2=1;
        //         ans[1]=nums[i];
        //     }
        //     else if(nums[i]==ans[0])
        //     {
        //         freq1++;
        //     }
        //     else if(nums[i]==ans[1]){
        //         freq2++;
        //     }
        //     else {
        //         freq1--;
        //         freq2--;
        //     }

        //  }
        //  int  cnt=0,cnt1=0;
        //  int flg=floor(n/3);
        //  for(int i=0;i<n;i++)
        //  {
        //     if(ans[0]==nums[i])
        //     {
        //         cnt++;
        //     }
        //     if(ans[1]==nums[i])
        //     {
        //         cnt1++;
        //     }
        //  }
        // if(cnt<=flg) ans.erase(ans.begin()+0);
        //  if(cnt1<=flg) ans.erase(ans.begin()+1);
         
         
        //  if(ans.size()>1&&ans[0]==ans[1] )  ans.pop_back();
        //  return ans;
        
     unordered_map<int,int> m;
     int n=nums.size();
     int flag=floor(n/3);
     vector<int> ans;
     for(int i=0;i<n;i++)
     {
        m[nums[i]]++;

     }
     for (auto it:m)
     {
        if(it.second>flag)
        {
            ans.push_back(it.first);
        }
     }
     
    

     return ans;



    }
};