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

Unpacking
---------

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

List Comprehension
------------------

파이썬의 꽃 중에 하나로, 한국어로는 **지능형 리스트** 라고도 합니다.

그래도 List Comprehension은 워낙 유명해서 아시는 분들이 조금 많은 것 같지만, 그래도 중요한 내용이니 한 번은 이야기 하고 넘어가겠습니다.

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
> (변수를 활용해 만들 값) for (변수 명) in (순회할 수 있는 값)

그렇기 때문에 List Comprehension으로 된 코드를 읽을 때는, 앞에부터 읽는게 아니라, for 뒤 부터 읽으면 꽤 편해요.

이걸 인지하고 위 코드를 다시 보면, _list에 있는 원소를 dt라고 하고, 앞에 있는 `1 if dt in _set else 0`에 대입한다는 이야기네요.

해당 내용은 _set에 원소가 들어있으면 1, 아니면 0을 리턴하라는 말이네요? 휴! 드디어 해석했습니다.

물론 다차원 배열도 사용할 수 있습니다.

```python
square = [[x ** 2 for x in range(3)] for _ in range(3)]
print(square) # [[1, 4, 9], [1, 4, 9], [1, 4, 9]]
```

코드의 길이를 확실히 줄일 수 있다는 장점이 있지만, 너무 길면 가독성도 해치고, 코드를 작성하는 본인도 "내가 뭘 하고 있지?" 라는 생각이 들 수 있습니다. 예를 들자면...

```python
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print([[x for x in row if x % 3 == 0] for row in matrix if sum(row) >= 10]) # [[6], [9]]
```

제발 이러진 마세요...

참고로, 리스트 뿐만이 아니라 tuple, set, dict도 만들 수 있습니다.
dict의 경우 뒷 부분에서 zip을 배우고 나면 정말 요긴하게 쓸 수 있습니다. (즉, 다음에 다룬다는 이야기입니다.) 사용법 자체는 List Comprehension과 유사합니다.
* * *

Dictionary 잘 쓰기
------------------

파이썬을 교양수업으로 듣던, 책으로 조금만 공부하던, Dictionary와 Set에 대해서는 접해봤을 것 입니다.

다만 처음 배우는 입장에선 '굳이 이걸 사용해야 할까?' 라는 생각을 많이 하더라고요. 어디에 사용하면 좋은지, 그리고 어떻게 해야 잘 사용할 수 있을지 한 번 알아봅시다.

Dictionary와 Set은 *Hash Table* 구조를 띄고 있습니다. (해시에 대해 잘 모르신다면, [여기](https://github.com/VSFe/Algorithm_Study/blob/main/Concept/05_Heap_Hash/Ch.05_%ED%9E%99_%ED%95%B4%EC%8B%9C_Python.pdf)를 봅시다.) 그래서 삽입, 삭제, 탐색 연산의 시간복잡도는 O(1) 입니다.

초보자분들이 가장 많이 하는 실수가, **값을 찾기 위해 list에서 in을 사용한다는 것** 입니다. 아니 그게 뭐가 문제냐고요?

```python
data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for i in range(100):
    if i in data:
        print(1)
```

해당 코드는 데이터를 순차적으로 탐색합니다. 그러니까 여기선 하나의 숫자를 찾기 위해 최대 10번 데이터를 확인해야 한다는 이야기겠죠.

뭐 데이터 양이 작다면 모르겠지만, 데이터양이 많으면 많아질수록 엄청나게 시간이 많이 소요됩니다. 당장 리스트에 100,000개의 원소가 있는데 20,000개의 랜덤 데이터가 여기 안에 있는지 찾는다고 생각해보세요.

이럴땐 set을 사용해야 합니다.

```python
data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
_data_set = set(data)

for i in range(100):
    if i in data:
        print(1)
```

실제로 몇 백만개의 데이터가 있는 set에 약 10만 번 정도의 in 연산을 시행해도 1초도 안 걸리는 시간에 완료하는데, list를 사용하게 되면 몇 시간 이상 걸릴 수 있습니다.

또한 set의 구조상, 같은 값이 들어올 수 없다는 것은 모두가 아실겁니다. 이걸 응용하면 다음과 같은 것도 가능합니다.

```python
i_want_to_erase_duplicate_element = [21, 31, 65, 21, 58, 94, 13, 31, 58]
completed_list = list(set(i_want_to_erase_duplicate_element)) # 21, 31, 65, 58, 94, 13

test_list = ['Test', 'test', 'TEST', 'tteesstt']
converted_list = list(set(map(lambda string: string.lower(), test_list))) # test, tteesstt
```

set은 iterable한 데이터를 기반으로 만들 수 있으니, 그걸 다시 list로 바꿔주면 중복된 값이 제거된 list가 만들어집니다.

아래 코드는 조금 어려울텐데, 우리는 lambda를 **익명 함수**라고 합니다. 뒤에 있는 `string`은 각각의 값을 string이라고 지칭하겠다고 선언하는 겁니다. 즉, 각각의 데이터를 소문자로 바꾸고, 그걸 set으로 바꾸고, 다시 list로 돌린거죠.

set은 끝난 것 같고, 이제 dictionary를 다뤄보겠습니다.

dictionary는 키와 쌍으로 이루어져 있습니다. 그렇다면 어떻게 생성할까요?

```python
fruit = ['apple', 'grape', 'orange', 'banana']
price = [3200, 15200, 9800, 5000]
_dict = {}

for i in range(len(price)):
    _dict.append((fruit[i], price[i])) # {'apple' : 3200, 'grape' : 15200, 'orange' : 9000, 'banana' : 5000}
```

혹시 이렇게 하시나요?

여기서 **zip**에 대해 나옵니다. zip에 대해 파이썬 레퍼런스는,
> 각 iterables 의 요소들을 모으는 이터레이터를 만듭니다.

라고 하고 있습니다. 즉, 리스트를 묶어준다는 이야기겠네요. zip은 다양하게 활용할 수 있지만, dictionary를 만들 때도 유용하게 쓰일 수 있습니다.

```python
fruit = ['apple', 'grape', 'orange', 'banana']
price = [3200, 15200, 9800, 5000]

_dict = dict(zip(fruit, price)) # {'apple' : 3200, 'grape' : 15200, 'orange' : 9000, 'banana' : 5000}
```

이제 생성은 다 되었네요!

일반적으로 딕셔너리에서 없는 값을 찾으려고 하면, 오류가 납니다.

```python
fruit = ['apple', 'grape', 'orange', 'banana']
price = [3200, 15200, 9800, 5000]
_dict = dict(zip(fruit, price))

print(_dict['strawberry']) # Error!
```

그래서 이걸 회피하기 위해, 처음 배우는 분들은 in 옵션을 사용해서 데이터가 있는지 확인하고, 없으면 값을 추가하고, 있으면 출력하는 방식으로 넘어갑니다. 그런데, 꼭 if를 써야 할까요?

```python
fruit = ['apple', 'grape', 'orange', 'banana']
price = [3200, 15200, 9800, 5000]
_dict = dict(zip(fruit, price))

print(_dict.setdefault('strawberry', 0)) # 0
```

`setdefault`는 딕셔너리에 값이 있을 땐 해당 값을 리턴하고, 값이 없을 땐 두번째 인자로 넘겨준 값을 추가하고 추가한 값을 리턴합니다.

참고로 해당 메소드를 활용한 *유사* dictionary가 있습니다. 우리는 이것을 **defaultdict** 라고 부르는데요,

```python
from collections import defaultdict

movie_review = [('Train to Busan', 4), ('Clementine', 5), ('Parasite', 4.5), ('Train to Busan', 4.2), ('Train to Busan', 4.5), ('Clementine', 5)]

index = defaultdict(list)

for review in movie_review:
    index[review[0]].append(review[1]) # {'Train to Busan': [4, 4.2, 4.5], 'Clementine': [5, 5], 'Parasite': [4.5]}
```

defaultdict에서 값을 검색할 때, 값이 없으면 인자로 넘겨준 값이 default 값이 됩니다. 결국 찾을 때 마다 setdefault를 암묵적으로 실행해준다고 생각하면 될 것 같아요.

위에서 unpacking을 배울 때, 리스트나 튜플에서 사용할 수 있는 방법을 배웠습니다. 그런데 dictionary는 원소가 쌍이잖아요? 이걸 어떻게 해야 unpacking을 잘 할 수 있을까요?

```python
fruit = ['apple', 'grape', 'orange', 'banana']
price = [3200, 15200, 9800, 5000]
_dict = dict(zip(fruit, price))

print(*_dict.keys()) # apple grape orange banana
print(*_dict.values()) # 3200 15200 9800 5000
print(*_dict.items()) # ('apple', 3200) ('grape', 15200) ('orange', 9800) ('banana', 5000)
```

다음과 같은 keys, values, items를 통해 내부 값을 unpacking 할 수 있습니다.
* * *

Sorting
-------

정렬은 **sort()** 라는 메소드가 있고, **sorted()** 라는 함수가 있습니다.

어? 하나는 메소드고 하나는 함수라고요? 정확히 말하자면 전자의 경우 **리스트를 내부 정렬하는 메소드** 이고, 후자는 **컨테이너형 데이터를 받아 정렬된 리스트를 돌려주는 함수** 입니다.

예시를 보면 다음과 같습니다.

```python
_list = [5, 6, 4, 8, 2, 3]
sorted_list = sorted(_list) # 2, 3, 4, 5, 6, 8
_list.sort()
print(_list) # 2, 3, 4, 5, 6, 8

_set = {65, 12, 15, 156, 31, 54, 94, 82, 31}
_set.sort() # Error!!!!
print(sorted(_set)) # 12, 15, 31, 54, 65, 82, 94, 156
```

sorted()의 출력값이 **리스트**라는 것에 주목하세요. 애초에 dictionary와 셋은 순서가 없습니다.

내림차순 정렬은 쉽죠.

```python
_list = [5, 6, 4, 8, 2, 3]
sorted_list = sorted(_list, reversed = True) # 8, 6, 5, 4, 3, 2
```

그런데... 이런 경우는 어떻게 정렬해야 할까요?
> 튜플의 리스트를 정렬하고 싶은데, 첫번째 값으로 오름차순 정렬을 하는데 값이 같으면 두번째 값으로 내림차순 정렬하고 싶어...

정렬 기준이 복잡하네요... 우선 이 문제를 해결하기 전에, 정렬 함수의 또 다른 옵션을 봅시다.

```python
_list = [(1, 3), (8, 2), (2, 5), (4, 7)]
sorted_list = sorted(_list, key = lambda dt: dt[1]) # (8, 2), (1, 3), (2, 5), (4, 7)
```

lambda가 뭐죠? 우선 key는 함수를 입력 받습니다. 즉, lambda가 함수라는 것을 알 수 있습니다.

정확히 말해서, lambda는 **익명 함수**라는 것으로, 함수의 이름을 명시하지 않고 일회성으로 사용하기 위해 정의하는 것입니다. 여기서 *dt*는 함수에서 사용할 변수명으로, dt는 각각의 튜플을 저런식으로 사용하겠다는 겁니다.

즉, 저 문구를 정리하면, **튜플의 첫번째 값을 기준으로 정렬하겠다.** 라는 것이죠.

그렇다면 위에서 제기한 상황에선 어떻게 정렬을 해야할까요?

```python
_list = [(1, 3), (8, 2), (2, 5), (4, 7)]
sorted_list = sorted(_list, key = lambda dt: (dt[1], -dt[0])) # (8, 2), (1, 3), (2, 5), (4, 7)
```

이런식으로 해주면 됩니다. 조건이 여러개인 경우 다음과 같이 튜플 형태로 묶어주는데, 음수가 되면 내림차순으로 정렬한다고 생각하면 됩니다. (사실은 각각의 값이 음수가 되면 대소관계가 반전되기 때문에, 음수로 변환해서 대소관계를 비교해서 정렬하는 것입니다.)

lambda를 사용하면 정말 다양한 방식으로 정렬을 할 수 있습니다.

```python
_list = ["CHicken", "hamburger", "Sushi", "chocolate"]

print(sorted(_list)) # ['CHicken', 'Sushi', 'chocolate', 'hamburger']
print(sorted(_list, key = lambda dt: dt.lower())) # ['CHicken', 'chocolate', 'hamburger', 'Sushi']
```

일반적으로 문자열은 대소관계를 비교하기 때문에, 다음과 같이 모두 소문자로 바꿔버리면 대소관계 상관 없이 정렬을 할 수 있습니다.

* * *

문자열
-----

코딩테스트를 파이썬으로 보시는 분들의 일부는 문자열 처리의 장점을 내세웁니다. 실제로 파이썬은 다른 언어보다 문자열 처리가 좀 편한 편이죠. 대부분의 문자열 처리는 다들 아실테니, 많은 분들이 잘 모르는 내용을 이야기 해보려고 합니다.

`strip()`에 대해서는 들어보셨을 겁니다. 공백을 제거하는 함수죠?

```python
print('     asdasd     '.strip()) # asdasd
```

사실 이건 공백을 제거하는 함수가 아닙니다.

```python
print('===chicken==='.strip('=')) # chicken
```

쨔잔! 양 끝에 있는 문자열을 제거하는 함수였습니다. 넘겨주지 않으면 공백 문자로 인식해서 공백을 제거했던 것일 뿐입니다.
참고로, 두개 이상의 문자열을 넣어주면, 두개를 모두 지워버립니다. and 조건이 아니라 or 조건이에요!

문자열을 뒤집고 싶을 땐, 두 가지 방법이 있습니다. (사실 이건 iterable한 데이터에선 모두 사용할 수 있지만, 두번째 때문에 일부러 문자열에서 설명합니다.)

```python
string = 'I am Hungry...'
print(string[::-1])
print("".join(reversed(string)))
```

전자의 경우, 모든 iterable한 데이터에서 사용 가능합니다. (즉, 리스트도, 튜플도 가능한거죠.) 잘 모르시는 분들은 슬라이싱을 할 때 두개의 변수만 활용하지만, 세번째를 활용하면 슬라이싱이 더 무궁무진해집니다.

슬라이싱은 `string[시작:종료(포함 안 함):간격]` 구조를 띄고 있습니다. 즉, 마지막이 2이면 0, 2, 4... 번째 문자열을 꺼내오겠죠. -1은? 역순으로 뽑아옵니다. 간격도 물론 조정할 수 있습니다.

두번째의 경우 역순으로 뒤집은 iterator (iterable이 아닙니다!)을 리턴하는데, 그냥 출력하면 메모리 주소가 나오기 때문에 `for i in ~` 구조를 사용하거나 join을 사용합니다. (join 활용법은 아래에서 볼 수 있습니다!)

* * *

Combination/Permutation
-----------------------

가끔 모든 경우를 탐색해야 하는 상황이 있습니다. 대표적으로 이런 문제가 있겠네요?
>1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열을 모두 구하시오.

일반적으로 백트래킹을 활용해서 문제를 풉니다. 그렇지만, 다음과 같은 기능을 공부하면 굳이 백트래킹을 할 필요가 없습니다.

```python
import itertools
_list = [1, 2, 3, 4]
iter = itertools.combinations(_list, 2) # 12 13 14 23 24 34

iter = itertools.permutations(_list, 2) # 12 13 14 21 23 24 31 32 34 41 42 43

iter = itertools.combinations_with_replacement(_list, 2) # 11 12 13 14 22 23 24 33 34 44

iter = itertools.product(_list, repeat=2) # 11 12 13 14 21 22 23 24 31 32 33 34 41 42 43 44
```

`combination`은 모든 조합을 출력합니다. 즉, 중복이 없고, 순서를 구분하지 않습니다. `permutation`은 순열입니다. 중복은 없지만, 순서를 구분합니다.

`combination_with_replacement`는 중복이 가능한 조합입니다. 그래서 combination과 구분하여 11, 22, 33, 44가 새로 들어오죠. 마지막으로 `product`는 모든 가능한 경우의 수를 출력합니다. (**Cartesian Product**라고 합니다!)

combination을 활용하면 다음과 같은 문제도 해결할 수 있습니다.
> 전체 리스트에서 3개를 추출하여 곱했을 때, 그 곱의 최댓값을 출력하는 프로그램을 작성하시오.

방법은 굳이 알려드리지 않아도 알겠죠?

이처럼 단순히 순열, 조합을 구하는 것이 아닌, 다양한 완전탐색 상황에서 사용될 수 있으니 꼭 기억해두길 바라요.

* * *

기타 짤막한 도움말
------------------

### sum

파이썬에는 `reduce()`라는 함수가 있습니다. 예전 Python 2 시절에는 꽤 많이 썼는데, iterable한 값에 연속적으로 연산을 해 하나의 결과물을 출력하는 함수입니다.

```python
from functools import reduce
_list = [1, 2, 3, 4, 5]
def sum(a, b):
    return a + b

reduce(sum, _list) # 15
```

뭔가 쓸만할 것 같은 함수죠? 다만 Python 3 에서는 사용하지 않기를 권하고 있고, 이를 대체하기 위한 함수가 여럿 나왔습니다. (all(), any() 등등...)

저기에서 떨어져 나온 함수 중에 하나가 `sum()` 입니다. 뭐냐고요?

```python
_list = [1, 2, 3, 4, 5]
print(sum(_list)) # 15
```

이겁니다. 위에 있는 reduce()를 사용하는 것 보다 이게 몇 배는 더 쉽죠?

### join

리스트를 출력하고 싶은데, 출력 형태가 좀 특이합니다.

`1, 2, 3, 4, 5, 6, 7, 8` 처럼 출력을 하라고 하네요.

우선 이런 방법을 떠올릴 수 있지 않을까요?

```python
_list = [1, 2, 3, 4, 5, 6, 7, 8]
print(*_list, sep=', ') # 1, 2, 3, 4, 5, 6, 7, 8
```

음... 나쁘지 않습니다. 다만 sep은 출력 할 때만 사용할 수 있기 때문에, 문자열 조작과정에선 사용할 수 없습니다.
다른 방법은 없을까요?

```python
_list = [1, 2, 3, 4, 5, 6, 7, 8]
print(', '.join(_list))
```

오? 이게 뭘까요? join에 대한 정의를 봅시다.
> iterable 의 문자열들을 이어 붙인 문자열을 돌려줍니다.

정확히 말하면 str 클래스의 메소드인데, iterable한 데이터들 사이 사이에 문자열을 붙여서 문자열로 되돌려 줍니다.
그렇기 때문에 굳이 출력할 때가 아니더라도 사용할 수 있다는 장점이 있습니다.

### swap하기

C 스타일의 언어를 사용하다 보면, 두 값을 서로 바꿔야 할 때가 있습니다.

```c
int a = 3, b = 5;
int tmp = a;
a = b;
b = tmp;
```

이런식으로 임시 변수를 만들어서 값을 바꾸곤 하는데, 파이썬은 그냥

```python
a, b = b, a
```

하면 됩니다. 정말 쉽죠?

### for, while문 에서의 else

팁으로 넣어놓긴 하지만, 사용할 땐 좀 신중하게 사용해야 합니다.

이중 이상의 반복문을 사용하다가 중간에 break를 해야 할 때가 있습니다. 흔히 C 스타일의 언어는 다음과 같이 사용하죠.

```c
for (int i = 0; i < N; i++) {
    bool tmp = true;
    for (int j = 0; j < N; j++) {
        if (sample[i][j] != 1) {
            tmp = false;
            break;
        }
    }
    if(tmp) {
        // Some Code...
    }
}
```

이런식으로, flag에 해당하는 변수를 하나 만들어서 참/거짓 여부를 판단합니다. 파이썬은 이걸 다음과 같이 사용할 수 있습니다.

```python
for i in range(N):
    for j in range(N):
        if sample[i][j] != 1:
            break
    else:
        # Some Code...
```

어? 굉장히 낯선 코드입니다. for와 while 구문을 진행하다가 else가 나오면, **반복문을 break로 탈출하지 않았다면 진입**하는 구간으로 의미가 변경됩니다.

다만, 코드를 줄이는덴 좋긴 하지만, 상황에 따라 본인도 코드를 헷갈려 할 수 있습니다. 이걸 사용하기 전엔 한 번 생각해보고 (익숙해지고 싶다면 주석을 쓰셔도 되겠네요.) 사용해보는걸 권장합니다.


### Enumerate

for 를 사용하면 일반적으로 `range`를 사용해서 범위를 표시하거나, iterable한 데이터를 가져와서 내용물을 꺼냅니다.

다만 이런 경우가 있죠.

```python
_list = [a, b, c, d, e, f, g]
# 목표: (1, a), (2, b), (3, c)...
```

분명 iterable하게 for를 쓰고 싶지만, 앞에 있는 숫자 때문에 할 수 없이

```python
_list = [a, b, c, d, e, f, g]
for i in range(len(_list)):
    print(i, _list[i])
```

이렇게 쓰곤 합니다. 이걸 개선해보죠.

```python
_list = [a, b, c, d, e, f, g]
for idx, val in enumerate(_list):
    print(idx, val)
```

`enumerate`라는 단어는 **열거하다** 라는 의미를 갖고 있습니다. enumerate를 사용하면 **(인덱스, 값)** 의 형태의 튜플을 돌려줍니다. 즉, 힘들게 range()를 사용하지 않아도 되는거죠!

### Counter

가끔, 문자열에 들어간 글자를 셀 필요가 있습니다. 일반적으로는 딕셔너리를 사용해서 해결하곤 하죠.

```python
def countLetters(word):
    counter = {}
    for letter in word:
        counter.setdefault(letter, 0)
        counter[letter] += 1
    return counter

countLetters('Hello World') # {'H': 1, 'e': 1, 'l': 3, 'o': 2, ' ': 1, 'W': 1, 'r': 1, 'd': 1}
```

사실 이것도 충분히 쓸만합니다. 그런데 이걸 더 줄일 순 없을까요?

```python
from collections import Counter
Counter('hello world') # Counter({'l': 3, 'o': 2, 'h': 1, 'e': 1, ' ': 1, 'w': 1, 'r': 1, 'd': 1})
```

Counter는 다양한 메소드를 지원합니다.

```python
from collections import Counter
Counter('hello world').most_common() # [('l', 3), ('o', 2), ('h', 1), ('e', 1), (' ', 1), ('w', 1), ('r', 1), ('d', 1)]
Counter('hello world').most_common(2) # [('l', 3), ('o', 2)]
```

`most_common()`을 사용하면 전체 결과를 튜플의 리스트로 리턴하고, 숫자를 명시하면 상위 n개에 해당하는 결과만 출력합니다.

* * *

Reference
---------

- 파이썬 언어 레퍼런스 [이동](https://docs.python.org/ko/3/reference/index.html)
- 전문가를 위한 파이썬 (원제 Fluent Python) - 루시아누 하말류 [구매](https://www.aladin.co.kr/shop/wproduct.aspx?ItemId=88728476)
- Python Cookbook - 데이비드 비즐리, 브라이언 K. 존스 [구매](https://www.aladin.co.kr/shop/wproduct.aspx?ItemId=35468006)