n = int(input())
if n == 0:
    print(0)
    print(0, 0)
    exit(0)
a = [0]
for i in range(n):
    x = int(input())
    a.append(x)
MX = 300000
d = [[MX for i in range(n + 1)] for i in range(n + 1)]
p = [[MX for i in range(n + 1)] for i in range(n + 1)]
if a[1] > 100:
    d[1][0] = MX
    d[1][1] = a[1]
else:
    d[1][0] = a[1]
    d[1][1] = MX
for i in range(2, n + 1):
    if a[i] <= 100:
        d[i][n] = MX
        p[i][n] = [-1, -1]
        for j in range(n - 1, -1, -1):
            d[i][j] = min(d[i - 1][j] + a[i], d[i - 1][j + 1])
            p[i][j] = [i - 1, j]
            if d[i][j] == d[i - 1][j + 1]:
                p[i][j] = [i - 1, j + 1]
    else:
        d[i][0] = d[i - 1][1]
        p[i][0] = [i - 1, 1]
        for j in range(1, n):
            d[i][j] = min(d[i - 1][j - 1] + a[i], d[i - 1][j + 1])
            p[i][j] = [i - 1, j - 1]
            if d[i][j] == d[i - 1][j + 1]:
                p[i][j] = [i - 1, j + 1]
        d[i][n] = d[i - 1][n - 1] + a[i]
        p[i][n] = [i - 1, n - 1]
a1 = d[n][0]
k1 = 0
i = n
j = 0
mn = 0
for ptr in range(1, n + 1):
    if d[n][ptr] <= d[n][mn]:
        a1 = d[n][ptr]
        k1 = ptr
        j = ptr
        mn = ptr
kupons = []
while i != 1:
    if p[i][j][0] == i - 1 and p[i][j][1] == j + 1:
        kupons.append(i)
        i -= 1
        j += 1
    else:
        i, j = p[i][j]
kupons.sort()
print(a1)
print(k1, len(kupons))
print('\n'.join(list(map(str, kupons))))