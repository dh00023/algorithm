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
> 퀵정렬
> 1. pivot(기준값) 정하기
> 2. pivot보다 작은 원소들은 왼쪽, 큰 원소는 오른쪽
> 3. pivot을 기준으로 왼쪽 배열과 오른쪽 배열을 새로운 배열로 정하고 각 배열구간에서 1번과정 재귀적 반복
> 일반적으로 처음 또는 마지막 원소를 pivot으로 잡는다.

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
`compare`를 생략하면 오름차순

# 탐색기반 알고리즘 설계

탐색기반 설계방법은 문제를 탐색 가능한 형태로 구조화한 후 탐색해 나가는 알고리즘 설계방법이다.

##  탐색

탐색이란 같은 형태의 한 개 이상의 자료들이 적절한 형태로 구조화된 상태로 모여 있는 집합에서 특정 자료를 찾는 모든 작업을 말한다.
따라서 탐색할 자료가 저장되어 있는 **구조**를 파악하는 것이 중요하다.

- 선형구조(배열, 연결리스트로 표현될 수 있는 구조)
- 비선형구조(트리, 그래프 형태로 표현되는 구조)

탐색기반설계는 주어진 문제에서 주어진 데이터를 특성에 맞도록 구조화하고 이 자료를 적절한 방법으로 탐색해 나가면서 원하는 해를 찾는 알고리즘 설계법이다.

- 전체탐색법
- 부분탐색법(탐색할 영역을 적절한 방법으로 배제해 탐색의 효율을 높임)

### 1. 선형구조의 탐색

선형구조란 자료의 순서를 유일하게 결정할 수 있는 형태의 구조를 말한다. 2,3차원 구조라도 순서가 일정하게 정해져 있으면 이는 선형이라고 할 수 있다.

주로 **배열, 리스트**의 형태로 저장된다.

- 1차원 선형구조
- 다차원 선형구조(2차원 이상)

선형구조의 탐색은 선형구조로 저장된 자료들 중 원하는 것을 찾는 작업을 말한다.

- **순차탐색** : 자료의 특성에 관계없이 사용할 수 있는 일반적인 방법.
	- 전체탐색기법
	- O(n)
![](http://cfile30.uf.tistory.com/image/2133264853FDCD4C290295)

- **이분탐색**
	- O(log2 n)
	- 오름차순 or 내림차순으로 정렬된 선형구조에서 탐색

![](http://www.tipssoft.com/data/cheditor/0712/_copy9.gif)

`main`함수를 비롯한 모든 함수들은 함수 내에서 사용되는 모든 변수를 **지역변수**로 쓰는 것이 좋다.

전역변수는 지역변수보다 더 많은 공간을 확보할 수 있으며, 0으로 초기화된다.

- `lower_bound(S,S+n,k,[compare])`
- `upper_bound(S,S+n,k,[compare])`

### 2. 비선형구조의 탐색

**비선형구조**란 i번째 원소를 탐색한 다음 그 원소와 연결된 다른 원소를 탐색하려고 할 때, 여러 개의 원소가 존재하는 탐색구조를 말한다.

일반적으로 자료가 **트리**, **그래프**로 구성되어 있는 경우이다.

비선형구조의 탐색은 트리나 그래프의 모든 정점을 탐색하는 것이다.
비선형구조는 자료가 순차적으로 구성되어 있지 않으므로 단순히 반복문을 이용하기 어려우며 **스택**,**큐**같은 자료구조를 활용하여 탐색하는 것이 일반적이다.

- **깊이우선탐색(depth first search,dfs)**
- **너비우선탐색(breadth first search,bfs)**

![](http://cfile24.uf.tistory.com/image/23782C4E56AC1F3703588F)

정점은 일반적으로 상태나 위치를 표현한다. 간선은 정점들 간의 관계를 표현한다.

- 경로(path) : 정점s에서 임의의 정점t로 이동할 때, 사용한 정점들을 연결하고 있는 간선들의 순서로 된 집합
- 회로(cycle) : 그래프에서 임의의 정점s에서 같은 정점s로의 경로들

- 자기간선(loop) : 임의의 정점에서 자기 자신으로 연결하고 있는 간선
- 다중간선(multi edge) : 임의의 정점에서 다른 정점으로 연결된 간선의 수가 2개 이상
- 그래프의 차수(degree) : 임의의 한 정점에서 다늘 정점으로 연결된 간선의 수

#### 그래프의 구현

대표적인 입력형식은 첫 번째 줄에 정점의 수 n과 간선의 수 m
두번째 줄부터 간선으로 연결된 두 정점의 번호와 가중치
```
7 11
1 2 47
1 3 69
...
6 7 40
```

- 인접행렬(adjacency matrix)
	> 2차원 베열을 이용한다. 최대 정점의 수에 맞추어 2차원 배열 선언하고 각 ㅐ열의 칸에 연결된 정보 저장.
	
- - O(nm) 시간


![](http://cfile29.uf.tistory.com/image/24227840571C79650EEC39)

```cpp
#include <stdio.h>

int n, m, G[101][101];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
    {
    	int a, b, w;
        scanf("%d %d %d",&a, &b, &w);
        G[a][b]=G[b][a]=w;
    }
}
```



- 인접리스트(adjacency list)

인접행렬은 표현할 때 연결되지 않았던 부분까지 모두 표현이 된다. 연결되지 않은 부분을 0으로 표현한다. 알고리즘을 구현할 때에도 0까지 모두 조사를 해야하므로 효울이 떨어지는 경우가 많은데 인접리스트는 이러한 단점을 극복한다.

-	- O(n+m)시간

![](https://lh3.googleusercontent.com/22poilDCWxVN7yT5qhzxdzrw8en-V9qGjiTULqjtzDisaVWc4GdhtDOoVw1EP8Dcs2wcYF8WRBH1jEdnbm9HeDMsrCxOMWWCWzpm_zy6AnU3qD4Gk_aa76mul81GkqqS0hphsA)

`std::vector()`를 이용하여 간단하게 구현할 수 있다. 이때 인접행렬로 구현하는 것보다 공간을 적게 사용한다.

#### 깊이우선탐색(dfs)

그래프 중 회로가 없는 그래프를 트리라고한다.

1. 출발 정점을 트리의 가장 위에 있는 정점으로 한다.
2. 단계별 탐색을 한다.
3. 더 이상 진행할 수 없을 때는 백트랙(backtrack)-이전의 정점으로 되돌아간다.
4. 마지막 정점을 방문하면 깊이우선탐색이 완료된다.

```cpp
//인접리스트 백트랙킹 기법
//반복문 m번실행
bool visited[101];
void dfs(int k)
{
	for(int i=0;i<G[i].size();i++)
	    if(!visited[G[k][i],to])
        {
        	visited[G[k][i].to]=true;
            dfs(G[k][i]);
        }
    return;
}
```

```cpp
//인접행렬 백트릭킹 기법
//반복문 n^2번 실행
bool visited[101];
void dfs(int k)
{
	for(int i=0;i<=n;i++)
	    if(G[k][i] && !visited[G[k][i]])
        {
        	visited[G[k][i]]=true;
            dfs(G[k][i]);
        }
    return;
}
```

##### flood_fill

지뢰찾기, 뿌요뿌요 등 게임에서 많이 활용되는 알고리즘.
재귀함수를 이용해 깊이우선탐색을 구현한다. 하지만 재귀의 깊이가 너무 커지면 runtime error가 발생할 수 있다. 깊이가 너무 크다고 판단되면 너비우선탐색으로 처리하거나 재귀대신 스택을 이용한다.

dfs함수 부분의 4방향 탐색을 dx,dy를 이용해 작성할 수 있다.

```cpp
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

void dfs(int a, int b, int c)
{
	A[a][b]=c;
    for(int i=0;i<4;i++)
    	if(safe(a+dx[i],b+dy[i])&&A[a+dx[i]][b+dy[i]]==1)
        	dfs(a+dx[i],b+dy[i],c);
}
```

##### n-queen

n*n체스 보드판에 n개의 queen을 서로 공격하지 못하도록 배치하는 방법을 찾아내는 문제. 대각선 검사하면서 가야하는 알고리즘에 유용하다.

- 퀸은 8방향으로 모두 공격할 수 있다.


	1. 첫 번째 행, 첫 번째 열에 퀸을 놓는다.
	2. 다음 행에서 가능한 가장 왼쪽 열에 퀸을 놓는다.
	3. n번째 열에 더 이상 퀸을 놓을 수 없다면 백트랙한다.
	4. 마지막 행에 퀸을 놓으면 하나의 해를 구한 것이다.
	5. 모든 경우를 조사할 때까지 백트래킹해가며 해들을 구한다.

깊이우선탐색을 하며 해를 구할 때마다 카운트해 원하는 해를 구할 수 있다. 열과 대각선만 검사하면 된다.
대각선은 행+열 위치에 체크해 기울기가 증가하는 대각선 상에 퀸을 놓을 수 있는지 없는지 확인한다.
기울기가 감소하는 대각선은 **행과 열의 차가 일정**하다. `n+(행-열)`의 위치에 체크.
백트랙 시에 가장 중요한 점은 체크배열에 기록해 두었던 체크를 모두 해제해야한다.

#### 너비우선탐색(bfs)

핸져 정점에서 깊이가 1인 정점을 모두 탐색한 뒤 깊이를 늘려가는 방식이다. 너비우선탐색은 백트랙을 하지 않는다. 대신에 현재 정점에서 깊이가 1인 정점을 모두 방문해야하므로 **큐(queue)**라는 FIFO(First In First Out)자료구조를 활용해 현재 정점에서 깊이가 1 더 깊은 모든 정점을 순차적으로 큐에 저장해 탐색에 활용한다.

`std::queue()`를 활용하는 방법을 익힐 필요가 있다.

```cpp
//인접리스트에 저장했을 경우
#include <queue>
bool visited[101];

void bfs(int k)
{
	std::queue<int> Q;
    Q.push(k), visited[k]=1;
    while(!Q.empty())
    {
    	int current = Q.front();Q.pop();
        for(int i=0;i<G[current].size();i++)
        	if(!vistited[G[current][i]])
            {
            	visited[G[current][i]]=1;
                Q.push(G[current][i]);
            }
    }
}
```
전체를 탐색하는 데 있어서 반복문을 m번 실행하게 된다.

```cpp
//인접행렬
bool visited[101];

void bfs(int k)
{
	std::queue<int> Q;
    Q.push(k), visited[k]=1;
    while(!Q.empty())
    {
    	int current = Q.front();Q.pop();
        for(int i=0;i<G[current].size();i++)
        	if(G[current][i]&&!vistited[G[current][i]])
            {
            	visited[G[current][i]]=1;
                Q.push(G[current][i]);
            }
    }
}
```

전체 탐색하는데 있어서 반복문을 n^2번 실행하게된다.