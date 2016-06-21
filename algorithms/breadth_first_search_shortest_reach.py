def bfs(graph, start):
    """
    :param graph: a dictionary like this.
                    {
                    1: [2, 3, 4],
                    2: [5, 6],
                    3: [],
                    6: [],
                    5: [],
                    4: [7],
                    7: []
                    }
    :param start: starting point
    :return: a distance dictionary and a parent dictionary
    """
    length = 6
    distance = dict.fromkeys(graph.keys(), -1)
    distance[start] = 0

    parents = dict.fromkeys(graph.keys())
    queue = []
    queue.append(start)
    while queue:
        current = queue.pop(0)
        for node in graph[current]:
            if distance[node] == -1:
                distance[node] = distance[current] + length
                parents[node] = current
                queue.append(node)
    return distance, parents


t = int(input().strip())
results = []
for a0 in range(t):
    n, m = input().strip().split()
    n, m = [int(n), int(m)]
    graph = {}
    for i in range(n):
        graph[i+1] = []
    for a1 in range(m):
        start, end = input().strip().split()
        start, end = [int(start), int(end)]
        graph[start].append(end)
        graph[end].append(start)
    start = int(input().strip())
    this_result = []
    d, p = bfs(graph, start)
    for key in range(n):
        if key+1 != start:
            this_result.append(d[key+1])
    results.append(this_result)

for this in results:
    print(' '.join([str(elem) for elem in this]))

