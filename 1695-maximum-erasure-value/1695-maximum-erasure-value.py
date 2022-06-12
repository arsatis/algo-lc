class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        q, rolling, rolling_sum = deque([]), set(), 0
        maximal = 0
        for num in nums:
            if num not in rolling:
                q.append(num)
                rolling.add(num)
                rolling_sum += num
            else:
                while q[0] != num:
                    popped = q.popleft()
                    rolling.discard(popped)
                    rolling_sum -= popped
                popped = q.popleft()
                q.append(num)
            if rolling_sum > maximal:
                maximal = rolling_sum
        return maximal