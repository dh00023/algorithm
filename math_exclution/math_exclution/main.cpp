//
//  main.cpp
//  math_exclution
//
//  Created by dahye Jeong on 2017. 6. 3..
//  Copyright © 2017년 dahye Jeong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 약수의 합 구하기
void q1(){
    // 입력값 n이 100억이 최대값일 경우에는 int로는 값을 처리할 수 없으므로 long long int형을 활용해야한다.
    
    long long int n,sum=0,i;
    scanf("%lld",&n);
    //영역배제 - 1.모든 자연수 n에 대해 1과 n은 항상 n의 약수이다.
    // 2. 모든 자연수 n에 대하여, 2이상 n미만의 자연수들 중 가장 큰 n 의 약수는 n/2를 넘지 않는다.
    // 3. n = d(k) X d(c-k+1) k번째 원소와 c-k+1번째 원소의 곱은 항상 n이다.
    for(i=2;i*i<=n;i++)
        if(n%i==0)sum+=(i+n/i);
    if(i*i==n)sum+=i;
    printf("%lld",sum);
}

//소수 구하기
bool isPrime(int k){
    // 약수가 2개를 초과한다면 더 이상 탐색할 필요가 없다.
    // n이 소수라면 약수는 1과 n만 존재한다. 즉, 구간[2,n]에서 약수는 존재하지 않는다.
    // O(n^1/2)
    //
    for(int i=2;i*i<=k;i++){
        if(k%i==0)return false;
    }
    return true;
}

// 어떤 수에서 자릿수의 위치를 바꾸었을때 소수인것을 구하시오. ex) 23은소수, 32는 합성수
/*
    1. 숫자 자릿수 분리하기
    2. 순열 만들기
    3. 자료 정렬하기
    4. 소수 확인하기
 */
int a[6];
int allnum[2000],alli;

int compare(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int chk(int n)
{
    int i;
    if(n==1) return -1;
    
    for(i=2;i<n;i++)
        if(n%i==0) return -1;
    return 0;
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a; *a=*b; *b=temp;
}
void P(int i,int last)
{
    int num=0,j,k;
    if(i==last)
    {
        for(k=0;k<=last;k++)
            num+=a[k]*(int)pow((double)10,(double)k);
        allnum[alli++]=num;
    }
    else
        for(j=i;j<=last;j++)
        {
            swap(&a[i],&a[j]);
            P(i+1,last);
            swap(&a[i],&a[j]);
        }
}

void q3(){
    int n,i,last,prev=-1;
    scanf("%d",&n);
    for(i=0;i<6;i++)
        if(n!=0)
        {
            a[i]=n%10;
            n/=10;
            last = i;
        }
    P(0,last);
    qsort(allnum,alli,sizeof(int),compare);
    for(i=0;i<alli;i++)
    {
        if(chk(allnum[i])==0)
            if(prev!=allnum[i])
            {
                printf("%d ",allnum[i]);
                prev=allnum[i];
            }
    }
    if(prev==1)printf("0");
}

// 저울 추
// 1,3,9,27,81,243,729g 7개의 추 -> 3의 등비수열 -> 3진수!
// 물건의 무게가 입력되었을 때 양쪽의 접시에 어떤 추들을 올려놓아야 평행을 이루는지 결정하는 프로그램

int w[7]={1,3,9,27,81,243,729};
int output[9];
int three[7];
int i,j,n,idx;

void to3(int num)
{
    for(int i=0; num!=0 ;i++,num=num/3)
        three[i]=num%3;
}

// 3진법의 자릿수가 2인 자리찾기
int chk2(void)
{
    for(int i=0;i<7;i++)
        if(three[i]==2)
        {
            n=n+w[i];
            output[idx++]=w[i];
            return 2;
        }
    return 0;
}

void q4(){
    scanf("%d",&n);
    output[idx++]=n;
    
    do
        to3(n);
    while(chk2()==2); // 자릿값에 2가 하나라도 있으면 반복
    
    idx++; // 저울의 중심나타내기 -> 이미 초깃값이 0이므로 index를 더한다.
    
    for(i=0;i<7;i++)
        if(three[i]==1)
            output[idx++]=w[i];
    for(i=0;i<idx;i++)
        printf("%d ",output[i]);
}

// 삼각화단만들기 - a+b+c = n , a+b>c
// a와 b를 알면 c는 쉽게 구할 수 있다. => O(n^2)
// [n/3]<=c<n/2 , 1<=a<[n/3]
void q5(){
    int n,a,b,c,count=0;
    scanf("%d",&n);
    
    for(c=n/3;c<=n/2;c++)
        for(a=1;a<=n/3;a++)
        {
            b=n-(a+c);
            if(a+b>c && (a<=b&&b<=c))count++;
        }
    printf("%d",count);
}
int main() {
    q5();
    return 0;
}
