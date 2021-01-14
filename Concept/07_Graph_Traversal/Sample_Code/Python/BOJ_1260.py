"""
문제: DFS와 BFS (http://boj.kr/1260)
Tier: Silver 2 (2021.01.14 기준)
Comment: BFS와 DFS의 기본적인 활용법을 공부하는 문제입니다.
딱히 어렵지는 않죠?
"""

from collections import deque
import sys

N, M, V = map(int, sys.stdin.readline().rstrip().split())

graph = [[] for _ in range(N + 1)] # 배열의 인덱스는 0부터 시작하지만 데이터는 1부터 시작합니다.
visited = [False for _ in range(N + 1)]

def dfs(x, order: list):
    visited[x] = True
    order.append(x)
    for next in graph[x]:
        if not(visited[next]):
            dfs(next, order)

def bfs(start, order: list):
    q = deque()
    visited[start] = True
    q.append(start)
    order.append(start)

    while(len(q)):
        node = q.popleft()
        for next in graph[node]:
            if visited[next]:
                continue
            visited[next] = True
            order.append(next)
            q.append(next)


for _ in range(M):
    x, y = map(int, sys.stdin.readline().rstrip().split())
    graph[x].append(y)
    graph[y].append(x)

for i in range(N + 1):
    graph[i].sort()

dfsOrder = []
bfsOrder = []
dfs(V, dfsOrder)
visited = [False for _ in range(N + 1)]
bfs(V, bfsOrder)

print(*dfsOrder)
print(*bfsOrder)