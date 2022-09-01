class Solution {
public:
    double average(vector<int>& salary) {
        ios_base::sync_with_stdio(0);
        
        int low = min(salary[0], salary[1]), high = max(salary[0], salary[1]);
        double total = 0;
        
        for (int i = 2; i < salary.size(); ++i) {
            if (salary[i] < low) {
                total += low;
                low = salary[i];
                continue;
            }
            if (salary[i] > high) {
                total += high;
                high = salary[i];
                continue;
            }
            total += salary[i];
        }
        
        return total / (double) (salary.size() - 2);
    }
};