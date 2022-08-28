class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        int major = nums[0], count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                ++count;
                major = nums[i];
            }
            else if (major == nums[i]) count++;
            else --count;
        }
        return major;
    }
};