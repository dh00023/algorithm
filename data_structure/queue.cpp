//
//  queue.cpp
//  data_structure
//
//  Created by dahye Jeong on 2017. 6. 18..
//  Copyright © 2017년 dahye Jeong. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
 
 명령은 총 여섯 가지이다.
 
 push X: 정수 X를 큐에 넣는 연산이다.
 pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 size: 큐에 들어있는 정수의 개수를 출력한다.
 empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
 front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 */
int q[100001];
void queue1(){
    int n;
    scanf("%d",&n);
    int front=0,back = 0;
    while(n--){
        string s;
        cin >> s;
        if(s == "push"){
            int m;
            scanf("%d",&m);
            q[back]=m;
            back+=1;
        }else if(s == "pop"){
            if(front==back){
                printf("%d\n",-1);
            }else{
                printf("%d\n",q[front]);
                q[front]=0;
                front+=1;
            }
        }else if(s=="size"){
            printf("%d\n",back - front);
        }else if(s=="empty"){
            if(front==back){
                printf("%d\n",1);
            }else printf("%d\n",0);
        }else if (s == "front"){
            if(front==back){
                printf("%d\n",-1);
            }else{
                printf("%d\n",q[front]);
            }
        }else if (s == "back"){
            if(front==back){
                printf("%d\n",-1);
            }else{
                printf("%d\n",q[back-1]);
            }
        }
    }
}


/*
 조세퍼스 문제는 다음과 같다.
 
 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 M(≤ N)이 주어진다. 이제 순서대로 M번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, M)-조세퍼스 순열이라고 한다. 예를 들어 (7, 3)-조세퍼스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
 
 N과 M이 주어지면 (N,M)-조세퍼스 순열을 구하는 프로그램을 작성하시오.
 */

void jose(){
    int n,m;
    scanf("%d%d",&n,&m);
    
    queue<int> qu;
    for(int i=1;i<=n;i++){
        qu.push(i);
    }
    printf("<");
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            qu.push(qu.front());
            qu.pop();
        }
        printf("%d, ",qu.front());
        qu.pop();
    }
    printf("%d>",qu.front());
}
