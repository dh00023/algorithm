//
//  main.cpp
//  Question8to12
//
//  Created by dahye Jeong on 2017. 6. 3..
//  Copyright © 2017년 dahye Jeong. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

/* 리모컨 - 냉난방기의 온도 조절
  온도 1,5,10도 내리고 올리는 버튼
  현재 설정 온도와 변경하고자 하는 목표온도가 주어지면 이버튼을 이용해 목표온도로 변경
*/
//int a,b,res=40;
struct ELE{int v, cnt;};
queue<ELE> Q;

void q8()
{
    /* 깊이우선탐색
    
    if(cnt>res)return;
    if(temp == b)
    {
        if(cnt<res)res=cnt;
        return;
    }
    if(temp<b){
        q8(temp+10,cnt+1);q8(temp+5,cnt+1);q8(temp+1,cnt+1);
    }
    else{
        q8(temp-10,cnt+1);q8(temp-5,cnt+1);q8(temp-1,cnt+1);
    }
     */
    //너비우선탐색
    int a,b;
    ELE temp;
    scanf("%d %d",&a,&b);
    Q.push({a,0});
    while(!Q.empty())
    {
        temp = Q.front(),Q.pop();
        if(temp.v == b)
            break;
        if(temp.v<b)
        {
            Q.push({temp.v+10,temp.cnt+1});
            Q.push({temp.v+5,temp.cnt+1});
            Q.push({temp.v+1,temp.cnt+1});
        }
        else
        {
            Q.push({temp.v-10,temp.cnt+1});
            Q.push({temp.v-5,temp.cnt+1});
            Q.push({temp.v-1,temp.cnt+1});
        }
    }
    printf("%d",temp.cnt);
}

int main() {
    
    q8();
    
    return 0;
}
