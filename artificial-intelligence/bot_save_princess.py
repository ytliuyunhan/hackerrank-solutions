def displayPathtoPrincess(n, grid):
    m_i, m_j = find(grid, 'm')
    p_i, p_j = find(grid, 'p')
    horizontal = m_j - p_j
    vertical = m_i - p_i
    if horizontal >= 0:
        h_move = ['LEFT'] * horizontal
    else:
        h_move = ['RIGHT'] * (-horizontal)

    if vertical >= 0:
        v_move = ['UP'] * vertical
    else:
        v_move = ['DOWN'] * (-vertical)
    moves = h_move + v_move
    for move in moves:
        print(move)


def find(mat, value):
    for i in range(len(mat)):
        for j in range(len(mat)):
            if value == mat[i][j]:
                return i, j


m = int(input())
grid = []
for i in range(0, m):
    grid.append(input().strip())

displayPathtoPrincess(m, grid)
