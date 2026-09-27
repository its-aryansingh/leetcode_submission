class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        # All 8 possible legal moves a chess knight can make
        moves = [
            (-2, -1), (-2, 1), (-1, -2), (-1, 2),
            (1, -2), (1, 2), (2, -1), (2, 1)
        ]
        
        # dp[r][c] will store the probability of the knight being at cell (r, c)
        # Initially, at 0 moves, the probability is 1.0 at the starting position
        dp = [[0.0] * n for _ in range(n)]
        dp[row][column] = 1.0
        
        # Iterate for each move from 1 to k
        for _ in range(k):
            next_dp = [[0.0] * n for _ in range(n)]
            for r in range(n):
                for c in range(n):
                    if dp[r][c] > 0:
                        # Distribute the probability evenly to all 8 possible moves
                        for dr, dc in moves:
                            nr, nc = r + dr, c + dc
                            if 0 <= nr < n and 0 <= nc < n:
                                next_dp[nr][nc] += dp[r][c] / 8.0
            dp = next_dp
            
        # Sum up all the probabilities remaining on the board
        return sum(sum(row) for row in dp)
