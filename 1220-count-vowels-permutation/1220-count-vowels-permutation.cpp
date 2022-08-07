class Solution {
public:
    int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1, mod = 1e9 + 7;
        
        for (int j = 0; j < n - 1; ++j) {
            long za = a, ze = e, zi = i, zo = o, zu = u;
            a = (ze + zi + zu) % mod;
            e = (za + zi) % mod;
            i = (ze + zo) % mod;
            o = zi % mod;
            u = (zi + zo) % mod;
        }
        
        return (a + e + i + o + u) % mod;
    }
};