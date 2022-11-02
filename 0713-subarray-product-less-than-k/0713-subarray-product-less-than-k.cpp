class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int j=0,i=0,res=0,pro=1;
        
        for(j=0;j<nums.size();j++){
            pro*=nums[j];
            while(pro>=k && i<=j){
                pro/=nums[i];
                i++;
            }
            res+=(j-i+1);
        }
        return res;
    }
};