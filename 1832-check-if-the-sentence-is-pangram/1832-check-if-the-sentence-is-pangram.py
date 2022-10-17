class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        ctr = set(sentence)
        for c in string.ascii_lowercase:
            if c not in ctr: return False
        return True