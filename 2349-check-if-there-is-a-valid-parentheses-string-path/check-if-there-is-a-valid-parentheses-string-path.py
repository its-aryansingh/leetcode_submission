class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        
        # If the start is ')' or the end is '(', it can never be valid
        if grid[0][0] == ')' or grid[m-1][n-1] == '(':
            return False
            
        # The total length of the path is m + n - 1
        # A valid parentheses string must have an even length
        if (m + n - 1) % 2 != 0:
            return False
            
        memo = {}
        
        def dfs(r, c, balance):
            # Update balance based on the current cell
            if grid[r][c] == '(':
                balance += 1
            else:
                balance -= 1
                
            # If balance goes negative, this path is invalid
            if balance < 0:
                return False
                
            # Reached the bottom-right corner
            if r == m - 1 and c == n - 1:
                return balance == 0
                
            # Memoization check
            state = (r, c, balance)
            if state in memo:
                return memo[state]
                
            # Move right or down
            found_path = False
            if r + 1 < m:
                found_path = found_path or dfs(r + 1, c, balance)
            if c + 1 < n:
                found_path = found_path or dfs(r, c + 1, balance)
                
            memo[state] = found_path
            return found_path
            
        return dfs(0, 0, 0)
