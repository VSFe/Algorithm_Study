"""
문제: 바이러스 (http://boj.kr/2606)
Tier: Silver 3 (2021.01.14 기준)
Comment: 1번을 기준으로 탐색해서 몇 군데를 방문했는지 출력하면 됩니다.
"""

import sys

N = int(sys.stdin.readline().rstrip())
M = int(sys.stdin.readline().rstrip())

graph = [[] for _ in range(N + 1)]
visited = [False for _ in range(N + 1)]

for _ in range(M):
    x, y = map(int, sys.stdin.readline().split())
    graph[x].append(y)
    graph[y].append(x)

def dfs(x):
    visited[x] = True
    for next in graph[x]:
        if not(visited[next]):
            dfs(next)

dfs(1)
print(sum(visited) - 1)