class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        visited = set([start])
        stack = deque([start])
        while stack:
            idx = stack.pop()
            if arr[idx] == 0: return True
            
            s = idx + arr[idx]
            if s < len(arr) and s not in visited:
                stack.append(s)
                visited.add(s)
                
            d = idx - arr[idx]
            if d >= 0 and d not in visited:
                stack.append(d)
                visited.add(d)
        return False