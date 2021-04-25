"""
문제: 제로 (http://boj.kr/10773)
Tier: Silver 4 (2021.01.14 기준)
Comment: 0이 나올때 가장 최근의 값을 뺍니다.
즉, FIFO 구조를 띄고 있고, 자연스럽게 스택을 사용하시면 됩니다.
"""

import sys

N = int(sys.stdin.readline().rstrip())
_list = []
for i in range(N):
    tmp = int(sys.stdin.readline().rstrip())
    if tmp == 0:
        _list.pop()
    else:
        _list.append(tmp)

print(sum(_list))