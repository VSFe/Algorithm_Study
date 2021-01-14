"""
문제: 단지번호붙이기 (http://boj.kr/2606)
Tier: Silver 1 (2021.01.14 기준)
Comment: 배열을 그래프로 보고 해석해서 푸는 문제입니다.
배열 내에서 이동하는 문제는 정말 많이 나오는 유형이니, 이 문제를 통해서 꼼꼼히 공부하면 좋을 것 같아요.
"""

import sys

N = int(sys.stdin.readline().rstrip())
graph = [list(sys.stdin.readline().rstrip()) for _ in range(N)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
visited = [[False for _ in range(N)] for _ in range(N)]
component = []

def dfs(x, y, idx):
    visited[x][y] = True
    component[idx] += 1
    for i in range(4):
        X = dx[i] + x; Y = dy[i] + y
        if X < 0 or X == N or Y < 0 or Y == N:
            continue
        if not(visited[X][Y]) and graph[X][Y] == '1':
            dfs(X, Y, idx)

for i in range(N):
    for j in range(N):
        if not(visited[i][j]) and graph[i][j] == '1':
            component.append(0)
            dfs(i, j, len(component) - 1)

print(len(component), *sorted(component), sep = '\n')