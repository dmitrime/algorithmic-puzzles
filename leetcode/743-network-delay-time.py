class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        dist = [float('inf')] * (N+1)
        dist[K] = 0
        for _ in range(N-1):
            for u,v,t in times:
                if dist[v] > dist[u] + t:
                    dist[v] = dist[u] + t
        
        m = max(dist[1:])
        return m if m < float('inf') else -1
