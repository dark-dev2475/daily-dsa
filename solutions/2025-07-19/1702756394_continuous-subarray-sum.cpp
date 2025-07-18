class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> mod_seen;
        mod_seen[0] = -1;
        int prefix_mod = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefix_mod = (prefix_mod + nums[i]) % k;
            
            if (mod_seen.count(prefix_mod)) {
                if (i - mod_seen[prefix_mod] > 1) {
                    return true;
                }
            } else {
                mod_seen[prefix_mod] = i;
            }
        }
        
        return false;
    }
};






