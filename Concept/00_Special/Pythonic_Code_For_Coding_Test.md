Pythonic Code For Coding Test
=============================
Python은 다른 C-Sytle의 언어 (C, C++, JAVA, ...) 와 다른 특별한 문법들이 많습니다.

다만 코딩테스트를 위해 Python을 사용하거나, 기본적인 문법만 공부하고 사용하시는 분들은 Python만의 특유의 문법 (Pythonic 한 코드라고도 합니다.)을 잘 활용하지 못하는 경우가 많습니다.

이 자료는 다음과 같은 분들에게 추천합니다.
- 파이썬 문법을 알고 있지만 Pythonic한 코드를 작성하는데 어려움을 겪는 분들
- C-Style 언어를 사용하다 코딩 테스트를 위해 Python을 사용하시는 분들

꼭 모든 내용을 기억할 필요는 없고, 간단하게 30분 정도 시간을 잡고 읽어보시면서 "이런 문법도 있구나!"하고 이해하고 넘어가면 좋을 것 같습니다.

목차 (예정)
-----------
내용이 확정되는 대로 작성하겠습니다.
* * *
## Unpacking
파이썬으로 알고리즘 문제를 좀 풀다보면 이 문법은 친숙할겁니다.

```python
a, b = map(int, input().split())
```
이것은 iterable (모든 반복 가능한 객체를 iterable 하다고 합니다! 리스트, 튜플, 문자열 등등...) 한 데이터엔 모두 가능한 문법입니다.

그런데 이런 상황이 있을 겁니다.

> 입력 받은 list에서 첫번째, 마지막 값만 얻고 싶어!

또는

> 입력 받은 list에서 첫번째, 마지막 값을 제외하고 싶어!

이런 경우는 어떻게 해야 할까요?
```python
_list = [1, 2, 3, 4, 5]
first_index, *rest, last_index = _list
print(rest) # 2 3 4
```
간단하네요?
파이썬은 *(asterisk)를 다음과 같은 상황에 사용합니다.

- 곱셈, 거듭제곱
- List형 컨테이너를 반복해서 확장
- 가변 인자
- Unpacking

위에서 rest에 사용한 것은 가변인자 입니다. 즉, 인자의 갯수가 몇개가 될지 확실하지 않을때 사용하는 거죠.
first_index와 last_index가 앞과 끝을 가져가면, rest가 나머지를 가져가는 겁니다.

그렇다면 Unpacking은 뭘까요?
일단 아래 예시를 보겠습니다.
```python
_list = [1, 2, 3, 4, 5]
for num in _list:
    print(num, end = ' ') # 1 2 3 4 5
```
_list내 원소들을 출력하는 평범한 코드입니다. 그렇다면 이건 어떨까요?
```python
_list = [1, 2, 3, 4, 5]
print(*_list) # 1 2 3 4 5
```
놀랍게도 동일한 결과를 얻을 수 있습니다. 이것을 **List Unpacking** 이라고 부릅니다.

사실 list뿐만이 아니라, 컨테이너형 구조에선 모두 적용할 수 있습니다. 튜플에서도 되고, set에서도 가능해요.

Unpacking을 이야기 했으니 살짝 다른 이야기를 해보겠습니다. 이건 어떤가요?
```python
a, b, c = [1, 2, 3]
d = a, b, c
print(d) # (1, 2, 3)
```
오잉? 첫번째 줄은 알겠는데 두번째 줄은 뭔가요?

저런식으로 하나의 변수에 여러 값을 할당하게 되면 튜플로 묶이게 됩니다. 위에서 튜플로 Unpacking을 할 수 있다고 했으니, 이건 Packing이라고 생각하면 되겠네요.
* * *
## List Comprehension
파이썬의 꽃 중에 하나로, 한국어로는 **지능형 리스트** 라고도 합니다.

그래도 List Comprehension은 워낙 유명해서 아시는 분들이 조금 많은 것 같을테니, 조금 헤비하게 들어가보겠습니다.

먼저 기본형을 보면,
```python
_list = [i for i in range(10)] # 0 1 2 3 4 5 6 7 8 9
```
이런 구조를 띄고 있습니다. 사실 이런 구조는 보기 쉬우니까 처음 보는 사람들도 적당히 이해하고 넘어갈 수 있습니다.

그렇다면 이건 어떨까요?
```python
## 백준 온라인 저지 1920번 "수 찾기" (http://boj.kr/1920)
import sys
input = sys.stdin.readline

_ = input()
_set = set(map(int, input().split()))
q = input()
_list = list(map(int, input().split()))

print(*[1 if dt in _set else 0 for dt in _list], sep = '\n')
```
어... 이해가 잘 가시나요? 가신다면 그냥 스크롤을 아래로 쭉~~ 내리시면 됩니다.

우선 List Comprehension은 다음과 같은 구조를 띄고 있습니다.
* * *
Reference
---------
- 파이썬 언어 레퍼런스 [이동](https://docs.python.org/ko/3/reference/index.html)
- 전문가를 위한 파이썬 (원제 Fluent Python) - 루시아누 하말류 [구매](https://www.aladin.co.kr/shop/wproduct.aspx?ItemId=88728476)
- Python Cookbook - 데이비드 비즐리, 브라이언 K. 존스 [구매](https://www.aladin.co.kr/shop/wproduct.aspx?ItemId=35468006)