def find_dirt(mat, value):
    for i in range(len(mat)):
        for j in range(len(mat)):
            if value == mat[i][j]:
                return i, j


def next_move(posr, posc, board):
    dirt_i, dirt_j = find_dirt(board, 'd')
    horizontal = posc - dirt_j
    vertical = posr - dirt_i
    if horizontal > 0:
        move = 'LEFT'
        posc -= 1
    elif horizontal < 0:
        move = 'RIGHT'
        posc += 1
    elif vertical > 0:
        move = 'UP'
        posr -= 1
    elif vertical < 0:
        move = 'DOWN'
        posr += 1
    else:
        move = 'CLEAN'
    return posr, posc, move


if __name__ == "__main__":
    pos = [int(i) for i in input().strip().split()]
    board = [[j for j in input().strip()] for i in range(5)]
    posr = pos[0]
    posc = pos[1]
    posr, posc, move = next_move(posr, posc, board)
    print(move)
