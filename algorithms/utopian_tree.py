def get_growth(n):
    height = 1
    springs = (n+1) // 2
    summers = n // 2
    for i in range(summers):
        height *= 2
        height += 1
    if springs > summers:
        height *= 2
    return height


t = int(input().strip())
results = []
for a0 in range(t):
    n = int(input().strip())
    results.append(get_growth(n))

for result in results:
    print(result)
