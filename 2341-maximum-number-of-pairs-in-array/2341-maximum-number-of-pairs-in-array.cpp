class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        vector<int> answer(2);
        int counts[101] = { 0 };
        
        for (int& i : nums) {
            if (!counts[i]) {
                ++counts[i];
                ++answer[1];
            } else {
                --counts[i];
                ++answer[0];
                --answer[1];
            }
        }
        
        return answer;
    }
};