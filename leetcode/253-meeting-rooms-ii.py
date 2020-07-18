class Solution:
    def minMeetingRooms(self, intervals):
        intervals = sorted(intervals, key=lambda x: x.start)
        h = [intervals[0].end]
        
        for i in range(1, len(intervals)):
            c = intervals[i]
            if c.start >= h[0]:
                heappushpop(h, c.end)
            else:
                heappush(h, c.end)
        return len(h)
