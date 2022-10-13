class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target: return 0
        boards = {}
        for bus, route in enumerate(routes):
            for stop in route:
                if stop not in boards: boards[stop] = [bus]
                else: boards[stop].append(bus)
        
        visited = set()
        queue = deque([source])
        res = 0
        while queue:
            res += 1
            cur_level = len(queue)
            for i in range(cur_level):
                cur = queue.popleft()
                for bus in boards[cur]:
                    if bus in visited: continue
                    visited.add(bus)
                    for stop in routes[bus]:
                        if stop == target: return res
                        else: queue.append(stop)
        return -1
        