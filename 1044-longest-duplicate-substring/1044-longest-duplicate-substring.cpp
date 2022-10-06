#define maxn 300005

// Solution 2: Dragonfly algorithm
class Solution {
    int wa[maxn], wb[maxn], wv[maxn], ws[maxn], sa[maxn], rank[maxn], height[maxn];
    
    int cmp(int* r, int a, int b, int l) {
        return r[a] == r[b] && r[a + l] == r[b + l];
    }
    
    void da(int* r, int* sa, int n, int m) {
        int i, j, p, *x = wa, *y = wb, *t;
        for (i = 0; i < m; ++i) ws[i] = 0;
        for (i = 0; i < n; ++i) ++ws[x[i] = r[i]];
        for (i = 1; i < m; ++i) ws[i] += ws[i - 1];
        for (i = n - 1; i >= 0; --i) sa[--ws[x[i]]] = i;
        for (j = 1, p = 1; p < n; j <<= 1, m = p) {
            for (p = 0, i = n - j; i < n; ++i) y[p++] = i;
            for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
            for (i = 0; i < n; ++i) wv[i] = x[y[i]];
            for (i = 0; i < m; ++i) ws[i] = 0;
            for (i = 0; i < n; ++i) ++ws[wv[i]];
            for (i = 1; i < m; ++i) ws[i] += ws[i - 1];
            for (i = n - 1; i >= 0; --i) sa[--ws[wv[i]]] = y[i];
            for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; ++i)
                x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
    }
    
    void callheight(int* r, int* sa, int n) {
      int i, j, k = 0;
      for (i = 1; i < n; ++i) rank[sa[i]] = i;
      for (i = 0; i < n; height[rank[i++]] = k)
          for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; ++k);
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    string longestDupSubstring(string s) {
        s = s + '0';
        int n = s.size(), r[n];
        
        for (int i = 0; i < n; ++i) r[i] = s[i] - '0';
        da(r, sa, n, 300);
        callheight(r, sa, n);
        
        int lcp = 0, idx = 0;
        for (int i = 1; i < n; ++i) {
            if (height[i] > lcp) {
                lcp = height[i];
                idx = sa[i];
            }
        }
        return s.substr(idx, lcp);
    }
};

// Solution 1: Karp-Rabin
// class Solution {
//     string dupWithLength(string& s, int n) {
//         unordered_map<int, int> hashes;
//         int shift = 5, mod = 5e7 + 17, multiplier = 1, sHash = 0;
        
//         for (int i = 1; i < n; ++i) multiplier = (multiplier << shift) % mod;
//         for (int i = 0; i < n; ++i) sHash = ((sHash << shift) + s[i] - 'a') % mod;
//         hashes[sHash] = n - 1;
        
//         for (int i = n; i < s.size(); ++i) {
//             sHash = (sHash + mod - (multiplier * (s[i - n] - 'a') % mod)) % mod; // remove leftmost element
//             sHash = ((sHash << shift) + s[i] - 'a') % mod; // add rightmost element
//             if (hashes.find(sHash) != hashes.end() &&
//                 s.substr(i - n + 1, n) == s.substr(hashes[sHash] - n + 1, n)) return s.substr(i - n + 1, n);
//             hashes[sHash] = i;
//         }
//         return "";
//     }
// public:
//     string longestDupSubstring(string& s) {
//         int lo = 0, hi = s.size() - 1;
//         string maxDup = "", dup;
//         while (lo < hi) {
//             int mid = (lo + hi + 1) >> 1;
//             if ((dup = dupWithLength(s, mid)) == "") hi = mid - 1;
//             else {
//                 lo = mid;
//                 if (mid > maxDup.size()) maxDup = dup;
//             }
//         }
//         return maxDup;
//     }
// };