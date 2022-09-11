class Solution {
    void f(int n, int k, vector<vector<int>>& combs, vector<int>& comb) {
        if (comb.size() == k) combs.push_back(comb);
        else for (int i = comb.empty() ? 1 : comb.back() + 1; i <= n; ++i) {
            comb.emplace_back(i);
            f(n, k, combs, comb);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> tmp;
        tmp.reserve(k);

        if (k == 1) {
            for (int i = 1; i <= n; ++i) {
                tmp.push_back(i);
                result.push_back(tmp);
                tmp.pop_back();
            }

            return result;
        }

        if (k == n) {
            for (int i = 1; i <= n; ++i) {
                tmp.push_back(i);
            }
            result.push_back(tmp);
            return result;
        }

        for (int i = 1; i < k; ++i) {
            tmp.push_back(i);
        }

        while (!tmp.empty()) {
            int& index = tmp.back();

            for (int i = index + 1; i <= n; ++i) {
                tmp.push_back(i);
                result.push_back(tmp);
                tmp.pop_back();
            }

            int pos = 0;
            while (!tmp.empty()) {
                int& back = tmp.back();

                if (back + 1 >= n - pos++) {
                    tmp.pop_back();
                }
                else {
                    int i = ++back;
                    while (tmp.size() < k - 1)tmp.push_back(++i);
                    break;
                }
            }

        }

        return result;
    }
};