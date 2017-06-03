//
//  main.cpp
//  experiential_exclusion
//
//  Created by dahye Jeong on 2017. 6. 3..
//  Copyright © 2017년 dahye Jeong. All rights reserved.
//

#include <stdio.h>

// 현재 탐색한 거리 > 지금까지 구한 최소 경로의 거리 의 조건을 만족한 경우 더 이상 탐색하지 않아도 된다.
int n,m,G[1001][1001],sol,chk[1001],greedy_chk[1001];//단순 탐욕법
int counter; // 성능 검증을 위해 해를 구하기까지 몇 개의 상태를 탐색하는 지 카운팅

void greedy_ans(int V)
{
    int W=0,t;
    greedy_chk[V]=1;
    while(V!=n)
    {
        int min = 0x7fffffff;
        for(int i=0;i<=n;i++)
            if(!greedy_chk[i]&&G[V][i]&&G[V][i]<min)
            {
                greedy_chk[i]=1;
                min=G[V][i];
                t=i;
            }
        sol+=G[V][t];
        V=t;
    }
}
void solve(int V, int W)
{
    if(W>sol) return; //커팅
    counter++;
    if(V==n)
    {
        if(W<sol)sol=W;
        return;
    }
    for(int i=1;i<=n;i++)
        if(!chk[i]&&G[V][i])
        {
            chk[i]=1;
            solve(i,W+G[V][i]);
            chk[i]=0;
        }
}
void q1()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int s,e,w;
        scanf("%d %d %d",&s,&e,&w);
        G[s][e]=G[e][s]=w;
    }
    greedy_ans(1);
    solve(1,0);
    printf("%d\n",sol);
    printf("탐색한 정점수 %d",counter);
}

// minimum sum
// 현재까지의 합 > 지금까지 최소 합이면 배제할 수있다.
int m2[11][11];
int col_check[11],greedy_chk2[11];
int n2,min_sol,counter2;

void input(void)
{
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
        for(int j=0;j<n2;j++)
            scanf("%d",&m2[i][j]);
    
}
/* 단순 탐욕법
 1. 1행에서 가장 작은 수를 택하고 다음 행으로 진행한다.
 2. 다음 행에서 아직까지 선택되지 않은 열 중 가장 작은 수를 택하고 다음 행으로 진행한다.
 3. 아직 마지막 행을 마치지 않았으면 2단계로 간다.
 4. 지금까지 선택한 수들의 합을 처음 해로 한다.
 */
void greedy_ans2(int row)
{
    for(int i=row;i<n;i++)
    {
        int min = 0x7fffffff,k;
        for(int j=0;j<n;j++)
            if(!greedy_chk2[j]&& min > m2[i][j])
            {
                min = m2[i][j];
                k=j;
            }
        min_sol+=min;
        greedy_chk[k]=1;
    }
}
void solve2(int row,int score)
{
    if(score>min_sol)return; //커팅
    counter++;
    if(row==n2)
    {
        if(score<min_sol)
            min_sol=score;
        return;
    }
    for(int i=0;i<n2;i++)
    {
        if(col_check[i]==0)
        {
            col_check[i]=1;
            solve2(row+1,score+m2[row][i]);
            col_check[i]=0;
        }
    }
    return;
}
void q2(){
    input();
    greedy_ans2(0);
    solve2(0, 0);
    printf("%d",min_sol);
}

// 거스름돈
// 현재까지 사용한 동전의 수 > 지금까지 구해둔 최소 동전의 수 이면 배제
int m3,n3,coin[10],ans = 987654321,counter3;

/*
 단순탐욕법
 1. 현재 금액에서 지불할 수 있는 가장 큰 동전으로 가능한 만큼 지불한다.
 2. 만약 아직 돈이 남았다면, 다시 1단계로 간다.
 3. 지금까지 지불한 동전의 개수를 처음 해로 설정한다.
 */
void greedy_ans3(int mon)
{
    ans=0;
    while(mon)
    {
        for(int i=n3-1;i>=0;i--)
        {
            ans+=mon/coin[i];
            mon%=coin[i];
        }
    }
}
// d개의 동전으로 mon원을 사용한 상태
void solve3(int mon,int d){
    if(d>ans) return; //커팅
    if(mon>m3) return;
    counter3++;
    if(mon==m3)
    {
        if(d<ans)ans = d;
        return;
    }
    for(int i=0;i<n3;i++)
        solve3(mon+coin[i],d+1);
}
void q3(){
    scanf("%d %d",&m3,&n3);
    for(int i=0;i<n3;i++)
        scanf("%d",coin+i);
    greedy_ans3(m3);
    solve3(0,0);
    printf("%d\n",ans);
    printf("%d\n",counter3);
}

int main() {
    q3();
    return 0;
}
