class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        ios_base::sync_with_stdio(0);
        
		int length = nums.size(), index = 0;
		while (index < length) {
            if (nums[index] != val) ++index;
            else {
                nums[index] = nums[length - 1];
                --length;
            }
		}
        return length;
    }
};