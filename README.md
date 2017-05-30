## 정보과학과 문제

### 1. 계산 문제

수학적으로 계산 가능하며, 컴퓨터를 이용해 풀 수 있는 모든 문제들을 의미한다.

- **결정 문제(decision problem)**
- 탐색 문제(search problem)
- 카운팅 문제(counting problem)
- **최적화 문제(optimization problem)**
- 함수형 문제(function problem)

### 2. 결정 문제

계산 문제들 중 그 결과를 'YES' or 'NO'로 답할 수 있는 문제를 의미한다.

### 3. 최적화 문제

계산결과 얻은 후보 해들 중 가장 적절한 해를 찾는 형태의 문제를 말한다.

## 알고리즘과 실행시간 측정

### 1.알고리즘

주어진 문제를 해결하기 위한 단계 혹은 절차.
이 절차에는 입력값과 출력값이 존재해야하며, 유한한 단계를 거쳐서 반드시 종료되어야 한다.

알고리즘은 주로 자연어, 의사코드, 프로그래밍언어 등의 방법으로 기술할 수 있다.

#### 자연어
```
알고리즘 A
(1단계) 원소의 인덱스를 id로 정의한다.
(2단계) 집합 S에 대하여 1<=id<=n까지의 합을 구하고 이를 s라 한다.
(3단계) s를 출력하고 종료한다.
```

#### 의사코드(shudo code)

```
알고리즘 A
(1단계) id←1,s←0
(2단계) s = s + Sid, id ← id + 1
(3단계) id <= n goto 2단계
(4단계) print s
```

#### 프로그래밍 언어

```c
void A(int S, int n){
	int s = 0;
    for(int id = 1;id<=n;id++){
    	s = s + S[id];
    }
    printf("%d\n",s);
}
```

- 계산량 : n
- O(n)

알고리즘 효율성을 계산량으로 표현할 것이며, 계산량은 입력크기 n에 대한 실행시간을 나타낸다.

### 2. 실행시간의 측정

- 선택정렬(selection sort)는 자료가 10배 증가할수록 실행시간은 약 100배 증가한다. 따라서 n배커지면 n^2에 비례하여 증가한다.
- 퀵정렬(quick sort)는 백만개까지 정렬하는데 0.2초 이내로 처리하므로 알고리즘 효율의 차이를 직접 체감할 수 있음.

```cpp
// 퀵정렬 기반으로 동작하는 std::sort()사용
#include <algorithm>

std::sort()
```

- O(nlgn)으로 자료를 정렬하는 함수
- 배열,구조체, `std::vector`, `std::list`, `std::set`, `std::map`등 다양한 형태의 자료구조를 모두 정렬할 수있는 매우 강력한 정렬함수이다.

`std::sort(정렬할 자료의 시작 주소, 정렬할 자료의 마지막 주소,[비교함수 주소])`

```cpp
bool compare(int a, int b){
// 오름차순    return a<b;
// 내림차순
    return a>b;
}

bool comparep(POINT a, POINT b){
    if(a.x == b.x ) return a.y < b.y;
    else return a.x < b.x;
}

//처음부터 n-1번째까지 원소를 compare함수의 정의대로 정렬
std::sort(S,S+n,compare);
```