t y = rows - 1; y >= 0; y--)
    //     for (int x = cols; cols >= 0; x--)
    //     {
    //         if (x == cols)
    //             dp[y][x] = dp[y + 1][x] + grid[y][x];
    //         else
    //             dp[y][x] = min(dp[y + 1][x], dp[y][x + 1]) + grid[y][x];
    //     }