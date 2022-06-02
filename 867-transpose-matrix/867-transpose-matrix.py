class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        return tuple(zip(*matrix))