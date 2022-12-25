class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> answer;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) nums[i] += nums[i - 1];
        for (int c : queries){
            int x = c, pos = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
            answer.emplace_back(pos);
        }
        return move(answer);
    }
};
