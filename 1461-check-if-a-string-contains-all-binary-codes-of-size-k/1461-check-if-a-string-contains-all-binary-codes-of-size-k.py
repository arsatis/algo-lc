class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        # rolling hash, O(s)
        need = 1 << k
        got = [0] * need
        mask = need - 1
        hash_val = 0
        for i in range(len(s)):
            hash_val = ((hash_val << 1) & mask) | (int(s[i]))
            if i >= k - 1 and not got[hash_val]:
                got[hash_val] = 1
                need -= 1
                if need == 0:
                    return True
        return False
    
    # def hasAllCodes(self, s: str, k: int) -> bool:
        # set, O(sk)
        # d = set()
        # for i in range(len(s) - k + 1):
        #     d.add(s[i:i + k])
        # return len(d) == (1 << k)