def get_decent_number(n):
    # solve the diophantine equation
    # 5's: a = 3n
    # 3's: b = 5m
    # (n, m) = (5k+2N, -3k-N) for any integer k
    # we need 3k-N to be as small as possible
    if n % 3 == 0:
        k = -(n // 3)
    else:
        k = -(n // 3) - 1
    b = 5 * (-3 * k - n)
    a = n - b
    if ((a == 0) & (b == 0)) | (a < 0) | (b < 0):
        result = -1
    else:
        result = int('5' * a + '3' * b)
    return result


t = int(input().strip())
result = []
for a0 in range(t):
    n = int(input().strip())
    result.append(get_decent_number(n))

for i in result:
    print(i)
