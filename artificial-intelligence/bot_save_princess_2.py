def nextMove(n, r, c, grid):
    p_i, p_j = find(grid, 'p')
    horizontal = c - p_j
    vertical = r - p_i
    if horizontal > 0:
        move = 'LEFT'
        r -= 1
    elif horizontal < 0:
        move = 'RIGHT'
        r += 1
    elif vertical > 0:
        move = 'UP'
        c -= 1
    elif vertical < 0:
        move = 'DOWN'
        c += 1
    return move

def find(mat, value):
    for i in range(len(mat)):
        for j in range(len(mat)):
            if value == mat[i][j]:
                return i, j


n = int(input())
r, c = [int(i) for i in input().strip().split()]
grid = []
for i in range(0, n):
    grid.append(input())

print(nextMove(n, r, c, grid))
