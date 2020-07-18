class Solution:
    def flood(self, p, grid, seen):
        i, j = p
        if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[i]):
            return
        
        if p in seen or grid[i][j] == '0': # CONDITIONS
            return
        
        seen[(i, j)] = True
        
        self.flood((i+1, j), grid, seen)
        self.flood((i-1, j), grid, seen)
        self.flood((i, j+1), grid, seen)
        self.flood((i, j-1), grid, seen)

    def numIslands(self, grid: List[List[str]]) -> int:
        seen = {}
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == '1' and (i, j) not in seen: # CONDITIONS!
                    count += 1
                    self.flood((i, j), grid, seen)
        
        return count
