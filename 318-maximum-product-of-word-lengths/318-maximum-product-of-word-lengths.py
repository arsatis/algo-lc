class Solution:
    def maxProduct(self, words: List[str]) -> int:
        # dumb O(n^2) solution
        output = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                no_common = True
                for c in words[i]:
                    no_common = no_common and not (c in words[j])
                    if not no_common:
                        break
                if no_common:
                    output = max(output, len(words[i]) * len(words[j]))
        return output
            