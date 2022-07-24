class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def floor():
            q = deque([(0, len(matrix) - 1, 0, len(matrix[0]) - 1)]) # left, right, top, down
            while q:
                l, r, t, d = q.popleft()
                hmid, vmid = (l + r) >> 1, (t + d) >> 1
                if matrix[hmid][vmid] == target: return True
                elif matrix[hmid][vmid] < target:
                    if hmid + 1 <= r: q.append([hmid + 1, r, t, d])
                    if vmid + 1 <= d: q.append([l, r, vmid + 1, d])
                else:
                    if hmid - 1 >= l: q.append([l, hmid - 1, t, d])
                    if vmid - 1 >= t: q.append([l, r, t, vmid - 1])
            return False
        
        return floor()