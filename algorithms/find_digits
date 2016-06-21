def find_divisible(n):
    digits = [int(i) for i in str(n)]
    divisibles = [i for i in digits if i != 0]
    divisibles = [i for i in divisibles if n % i == 0]
    return len(divisibles)

t = int(input().strip())
results = []
for a0 in range(t):
    n = int(input().strip())
    results.append(find_divisible(n))

for result in results:
    print(result)
