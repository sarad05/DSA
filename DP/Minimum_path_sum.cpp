#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int dp[n][m];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1) //handling last cell of the grid
            {
                dp[i][j] = grid[i][j];
            }
            else if (i == n - 1) //for last column of the grid
            {
                dp[i][j] = dp[i][j + 1] + grid[i][j];
            }
            else if (j == m - 1) //handling last row of the grid
            {
                dp[i][j] = dp[i + 1][j] + grid[i][j];
            }
            else //handling rest of the grid
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
            }
        }
    }
    cout << dp[0][0];
    return 0;
}