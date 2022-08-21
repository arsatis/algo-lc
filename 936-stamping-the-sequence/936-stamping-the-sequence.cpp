class Solution {
public:
	bool replaceable(int i, string &t, string &s) {
		for (int j = 0; j < s.size(); ++j, ++i) {
			if (t[i] == '*' || s[j] == t[i]) continue;
			return false;
		}
		return true;
	}
    
	int replace(int i, string &t, string &s) {
		int cnt = 0;
		for (int j = 0; j < s.size(); ++j, ++i) {
			if (t[i] == '*') continue;
			t[i] = '*';
			++cnt;
		}
		return cnt;
	}
    
	vector<int> movesToStamp(string &s, string &t) {
		int st = 0;
		vector<bool> visited(t.size(), false);
		vector<int> res;
        
		while (st < t.size()) {
			bool flag = false;
			for (int i = 0; i <= t.size() - s.size() && st < t.size(); ++i) {
				if (visited[i]) continue;
				if (replaceable(i, t, s)) {
					st += replace(i, t, s);
					visited[i] = true;
					flag = true;
					res.push_back(i);
				}
			}
			if (!flag) return *new vector<int>();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};