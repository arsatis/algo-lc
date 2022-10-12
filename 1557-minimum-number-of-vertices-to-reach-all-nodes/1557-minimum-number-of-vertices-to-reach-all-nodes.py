class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        in_nodes = [[] for _ in range(n)]
        for edge in edges:
            in_nodes[edge[1]].append(edge[0])
        
        output = []
        for i in range(n):
            if len(in_nodes[i]) == 0:
                output.append(i)
        return output
        
        