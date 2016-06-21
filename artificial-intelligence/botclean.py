def next_move(posr, posc, path):
    next_dirt = path[0]
    horizontal = posc - next_dirt[1]
    vertical = posr - next_dirt[0]
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
        path.pop(0)
    return posr, posc, move, path


def find_dirt(mat, value):
    dirts = []
    for i in range(len(mat)):
        for j in range(len(mat)):
            if value == mat[i][j]:
                dirts.append((i, j))
    return dirts


def get_path(posr, posc, dirts):
    path = []
    for i in range(len(dirts)):
        #print(posr, posc)
        dist = [(abs(x - posr), abs(y - posc)) for (x, y) in dirts]
        dist = [x[0] + x[1] for x in dist]
        next_stop = dirts.pop(dist.index(min(dist)))
        #print(next_stop)
        path.append(next_stop)
        posr = next_stop[0]
        posc = next_stop[1]
    return path


# Tail starts here
if __name__ == "__main__":
    pos = [int(i) for i in input().strip().split()]
    board = [[j for j in input().strip()] for i in range(5)]
    dirts = find_dirt(board, 'd')
    posr = pos[0]
    posc = pos[1]
    path = get_path(posr, posc, dirts)
    posr, posc, move, path = next_move(posr, posc, path)
    print(move)
