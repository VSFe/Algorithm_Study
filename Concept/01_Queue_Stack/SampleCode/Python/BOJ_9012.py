"""
문제: 괄호 (http://boj.kr/9012)
Tier: Silver 4 (2021.01.14 기준)
Comment: 스택 하면 떠올릴 수 있는 가장 유명한 문제입니다.
그런데, 어차피 괄호 종류는 하나인데 굳이 스택을 써야 할까요?
(백준 pypy3 기준 효율성 1위 코드입니다 ㅎㅎ;;)
"""

import sys

N = int(sys.stdin.readline().rstrip())
result = ""

for i in range(N):
    testcase = sys.stdin.readline().rstrip()
    cnt = 0
    for c in testcase:
        cnt += 1 if c == '(' else -1
        if cnt < 0:
            result += "NO\n"
            break
    else:
        result += "YES\n" if cnt == 0 else "NO\n"

print(result)