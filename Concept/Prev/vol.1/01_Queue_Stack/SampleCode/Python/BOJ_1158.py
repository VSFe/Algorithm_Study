"""
문제: 요세푸스 문제 0 (http://boj.kr/1158)
Tier: Silver 5 (2021.01.12 기준)
Comment: 큐를 활용할 수 있는 대표적인 문제입니다.
출력이 조금 특이하기 때문에 출력만 유의해서 풀어주세요.
"""

from collections import deque

N, K = map(int, input().split())
_list = []
q = deque([i + 1 for i in range(N)])

while len(q) != 0:
    q.rotate(-K)
    _list.append(q.pop())

print('<' + ', '.join(map(str, _list)) + '>')