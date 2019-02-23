import sys
sys.setrecursionlimit(1500)
MAX = 110
INF = 100000000000000000000000000000000
s = input()
dp = [[INF for i in range(110)] for j in range(110)]
p = [[-1 for i in range(110)] for j in range(110)]
def echo(i, j):
    if i > j: return
    if i == j:
        return
    if p[i][j] == -1:
        print(s[i], end = '')
        echo(i + 1, j - 1)
        print(s[j], end = '')
    else:
        echo(i, p[i][j])
        echo(p[i][j] + 1, j)
def solve(i, j):
    if i == j:
        return 1
    if i > j:
        return 0
    if dp[i][j] != INF:
        return dp[i][j]
    if (s[i] == '(' and s[j] == ')') or (s[i] == '[' and s[j] == ']') or (s[i] == '{' and s[j] == '}'):
        dp[i][j] = min(dp[i][j], solve(i + 1, j - 1))
    for k in range(i, j):
        temp = solve(i, k) + solve(k + 1, j)
        if temp < dp[i][j]:
            p[i][j] = k
            dp[i][j] = temp
    return dp[i][j]
solve(0, len(s) - 1)
echo(0, len(s) - 1)