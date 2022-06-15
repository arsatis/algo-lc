class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1) + 1, len(word2) + 1
        med = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0: med[i][j] = j
                elif j == 0: med[i][j] = i
                else:
                    sub = 0 if word1[i - 1] == word2[j - 1] else 2
                    med[i][j] = min(med[i - 1][j - 1] + sub, med[i - 1][j] + 1, med[i][j - 1] + 1)
        return med[-1][-1]