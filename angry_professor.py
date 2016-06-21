t = int(input().strip())
result_list = []
for a0 in range(t):
    n,k = input().strip().split(' ')
    n,k = [int(n),int(k)]
    a = [int(a_temp) for a_temp in input().strip().split(' ')]
    on_time = [elem for elem in a if elem <= 0]
    if len(on_time) >= k:
        result_list.append('NO')
    else:
        result_list.append('YES')

for result in result_list:
    print(result)
