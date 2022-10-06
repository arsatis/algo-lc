// Solution 3: Suffix array
class SuffixArray {
public:
    using size_type = unsigned;
    using pointer = size_type*;
    using const_pointer = const size_type*;
    
private:
    template<typename S>
    inline static bool substring_equal(const S& s, size_type p1, size_type p2, size_type len) {
        for (size_type i = 0;i < len;++i)
            if (s[p1 + i] != s[p2 + i])
                return false;
        return true;
    }

    template<typename S>
    inline static void induced_sort(
        const S& s,
        pointer sa,
        bool* type,
        pointer pos,
        pointer lbuk,
        pointer sbuk,
        size_type n,
        size_type m,
        size_type n0) {
        std::fill_n(sa, n, 0);
        std::copy_n(lbuk + 1, m - 1, sbuk);
        sbuk[m - 1] = n;
        for (size_type i = n0; i-- > 0;) sa[--sbuk[s[pos[i]]]] = pos[i];
        
        std::copy_n(lbuk + 1, m - 1, sbuk);
        sbuk[m - 1] = n;
        sa[lbuk[s[n - 1]]++] = n - 1;
        for (size_type i = 0;i < n;++i)
            if (sa[i] > 0 && !type[sa[i] - 1])
                sa[lbuk[s[sa[i] - 1]]++] = sa[i] - 1;
        
        std::copy_n(sbuk, m - 1, lbuk + 1);
        lbuk[0] = 0;
        for (size_type i = n;i-- > 0;)
            if (sa[i] > 0 && type[sa[i] - 1])
                sa[--sbuk[s[sa[i] - 1]]] = sa[i] - 1;
    }

public:
    template<typename S>
    static void sais(const S& s, pointer sa, bool* type, pointer len, pointer pos,
                     pointer lbuk, pointer sbuk, size_type n, size_type m) {
        pos += n / 2;
		type[n - 1] = false;
		std::fill_n(len, n, 0);
		const pointer npos = pos;
		for (size_type p = n - 1, i = n - 1;i-- > 0;) {
			type[i] = s[i] != s[i + 1] ? s[i] < s[i + 1] : type[i + 1];
			if (!type[i] && type[i + 1]) {
				len[i + 1] = p - i;
				*--pos = i + 1;
				p = i + 1;
			}
		}
		const size_type n0 = npos - pos;
        
        std::fill_n(lbuk, m, 0);
		for (size_type i = 0;i < n;++i)
			++lbuk[s[i]];
		for (size_type sum = 0, i = 0;i < m;++i) {
			const size_type cur = lbuk[i];
			lbuk[i] = sum;
			sum += cur;
		}
        
        induced_sort(s, sa, type, pos, lbuk, sbuk, n, m, n0);
        
        size_type m0 = -1;
        size_type ppos = -1, plen = 0;
        for (size_type i = 0;i < n;++i) {
            if (len[sa[i]] == 0) continue;
            if (len[sa[i]] != plen || !substring_equal(s, sa[i], ppos, plen)) ++m0;
            plen = len[sa[i]];
            len[sa[i]] = m0;
            ppos = sa[i];
        }
        
        const pointer s0 = sa;
        const pointer sa0 = sa + n0;
        for (size_type i = 0;i < n0;++i) s0[i] = len[pos[i]];
        
        if (++m0 < n0) sais(s0, sa0, type + n, len, npos, sbuk, sbuk + n0, n0, m0);
        else for (size_type i = 0;i < n0;++i) sa0[s0[i]] = i;
        for (size_type i = 0;i < n0;++i) npos[i] = pos[sa0[i]];
        
        induced_sort(s, sa, type, npos, lbuk, sbuk, n, m, n0);
    }

private:
    std::unique_ptr<size_type[]> data;

public:
    const_pointer sa, rk, ht;

public:
    template<typename S>
    SuffixArray(const S& s, size_type n, size_type m)
        : data(std::make_unique<size_type[]>(3 * n)) {
        const auto type = std::make_unique<bool[]>(2 * n);
        const auto lbuk = std::make_unique<size_type[]>(m);
        const auto sbuk = std::make_unique<size_type[]>(std::max(n, m));
        const pointer sa = data.get(), rk = sa + n, ht = rk + n;
        sais(s, sa, type.get(), rk, ht, lbuk.get(), sbuk.get(), n, m);
        for (size_type i = 0;i < n;++i)
            rk[sa[i]] = i;
        for (size_type k = 0, i = 0;i < n;++i) {
            if (rk[i] == 0) continue;
            if (k > 0) --k;
            const size_type j = sa[rk[i] - 1];
            const size_type l = n - std::max(i, j);
            for (;k < l;++k) if (s[i + k] != s[j + k]) break;
            ht[rk[i]] = k;
        }
        this->sa = sa;
        this->rk = rk;
        this->ht = ht;
    }

    inline size_type suffix(size_type p) const {
        return sa[p];
    }

    inline size_type rank(size_type p) const {
        return rk[p];
    }

    inline size_type height(size_type p) const {
        return ht[p];
    }
};

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    string longestDupSubstring(string s) {
        const int n = s.size();
        SuffixArray sa(s, n, 128);
        int len = 0, pos = -1;
        for (int i = 1;i < n;++i) {
            if (sa.ht[i] > len) {
                len = sa.ht[i];
                pos = sa.sa[i];
            }
        }
        return pos == -1 ? "" : s.substr(pos, len);
    }
};

// Solution 2: Dragonfly algorithm
// #define maxn 300005
// class Solution {
//     int wa[maxn], wb[maxn], wv[maxn], ws[maxn], sa[maxn], rank[maxn], height[maxn];
    
//     int cmp(int* r, int a, int b, int l) {
//         return r[a] == r[b] && r[a + l] == r[b + l];
//     }
    
//     void da(int* r, int* sa, int n, int m) {
//         int i, j, p, *x = wa, *y = wb, *t;
//         for (i = 0; i < m; ++i) ws[i] = 0;
//         for (i = 0; i < n; ++i) ++ws[x[i] = r[i]];
//         for (i = 1; i < m; ++i) ws[i] += ws[i - 1];
//         for (i = n - 1; i >= 0; --i) sa[--ws[x[i]]] = i;
//         for (j = 1, p = 1; p < n; j <<= 1, m = p) {
//             for (p = 0, i = n - j; i < n; ++i) y[p++] = i;
//             for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
//             for (i = 0; i < n; ++i) wv[i] = x[y[i]];
//             for (i = 0; i < m; ++i) ws[i] = 0;
//             for (i = 0; i < n; ++i) ++ws[wv[i]];
//             for (i = 1; i < m; ++i) ws[i] += ws[i - 1];
//             for (i = n - 1; i >= 0; --i) sa[--ws[wv[i]]] = y[i];
//             for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; ++i)
//                 x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
//         }
//     }
    
//     void callheight(int* r, int* sa, int n) {
//       int i, j, k = 0;
//       for (i = 1; i < n; ++i) rank[sa[i]] = i;
//       for (i = 0; i < n; height[rank[i++]] = k)
//           for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; ++k);
//     }
// public:
//     string longestDupSubstring(string s) {
//         s = s + '0';
//         int n = s.size(), r[n];
        
//         for (int i = 0; i < n; ++i) r[i] = s[i] - '0';
//         da(r, sa, n, 300);
//         callheight(r, sa, n);
        
//         int lcp = 0, idx = 0;
//         for (int i = 1; i < n; ++i) {
//             if (height[i] > lcp) {
//                 lcp = height[i];
//                 idx = sa[i];
//             }
//         }
//         return s.substr(idx, lcp);
//     }
// };

// Solution 1: Rabin-Karp
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