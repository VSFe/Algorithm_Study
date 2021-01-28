"""
문제: 미로탐색 (http://boj.kr/2178)
Tier: Silver 1 (2021.01.18 기준)
Comment: 최단거리 -> BFS!
"""

from collections import deque
import sys

N, M = map(int, sys.stdin.readline().rstrip().split())
graph = [list(input()) for i in range(N)]
visited = [[0 for i in range(M)] for i in range(N)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs():
    dq = deque()
    dq.append((0, 0))
    visited[0][0] = 1

    while len(dq):
        x, y = dq.popleft()
        for i in range(4):
            X = x + dx[i]; Y = y + dy[i];
            if X < 0 or X == N or Y < 0 or Y == M:
                continue
            if graph[X][Y] == '1' and visited[X][Y] == 0:
                visited[X][Y] = visited[x][y] + 1
                dq.append((X, Y))
    
bfs()
print(visited[N - 1][M - 1])