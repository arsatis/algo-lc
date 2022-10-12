class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        in_nodes = [0] * n
        for edge in edges:
            in_nodes[edge[1]] += 1
        return [i for i in range(n) if in_nodes[i] == 0]
        
        