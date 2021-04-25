"""
문제: 카드 2 (http://boj.kr/2164)
Tier: Silver 4 (2021.01.12 기준)
Comment: 큐를 배웠으니 큐를 통해서 풀이 하였습니다.
한번은 그냥 빼고, 한번은 뺀 걸 다시 넣는데, 결국 두 연산을 한 번씩 하면 크기가 1씩 감소합니다.
즉 크기가 1이 될 때 까지 빼고, 빼서 넣고를 반복하면 쉽게 해결할 수 있겠네요.
물론 큐를 사용하지 않고 수식으로도 풀 수 있습니다.
어떻게 할 수 있을까요?
"""

from collections import deque

li = deque([i for i in range(1, int(input()) + 1)])

while len(li) >= 2:
    li.popleft()
    li.rotate(-1)

print(li[0])