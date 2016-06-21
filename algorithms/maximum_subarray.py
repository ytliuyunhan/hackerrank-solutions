def max_contiguous(l):
    best = cur = l[0]
    for i in l[1:]:
        cur = max(cur + i, i)
        best = max(best, cur)
    return best


def max_subarray(l):
    gt_zero = [i for i in l if i > 0]
    if len(gt_zero) > 0:
        return sum(gt_zero)
    else:
        return max(l)


t = int(input().strip())
conts = []
subs = []
for a0 in range(t):
    n = int(input().strip())
    arr = [int(a_temp) for a_temp in input().strip().split(' ')]
    max_cont = max_contiguous(arr)
    max_sub = max_subarray(arr)
    conts.append(max_cont)
    subs.append(max_sub)

for i in range(len(conts)):
    print(conts[i], subs[i])
