//
//  main.cpp
//  inputoutput
//
//  Created by dahye Jeong on 2017. 6. 12..
//  Copyright © 2017년 dahye Jeong. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

//두 수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
void plus1(){
    int a,b;
    cin >> a >> b;
    cout << a+b;
}
//첫째 줄에 A, 둘째 줄에 B가 주어진다. (0 < A, B < 10)
void plus2(){
    int a,b;
    cin >> a;
    cin >> b;
    cout << a+b;
}

//첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A,B < 10)
//출력 : 각 테스트 케이스마다 A+B를 출력한다.
void plus3(){
    int t;
    int a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        printf("%d\n",a+b);
    }
}

//입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A,B < 10)
void plus4(){
    int a,b;
    while(scanf("%d %d",&a,&b)==2){
        printf("%d\n",a+b);
    }
}

//A와 B가 모두 0인 경우에 프로그램을 종료한다.
void plus5(){
    int a,b;
    while(scanf("%d %d",&a,&b)==2){
        if(a==0 && b ==0) break;
        printf("%d\n",a+b);
    }
}
/*
 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. A와 B는 콤마(,)로 구분되어 있다. (0 < A,B < 10)
 */
void plus6(){
    int t;
    int a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d,%d",&a,&b);
        printf("%d\n",a+b);
    }
}

//각 테스트 케이스마다 "Case #x: "를 출력한 다음, A+B를 출력한다. 테스트 케이스 번호는 1부터 시작한다.
void plus7(){
    int a,b,t;
    int n=0;
    scanf("%d",&t);
    while(t--){
        n++;
        scanf("%d %d",&a,&b);
        printf("Case #%d: %d\n",n,a+b);
    }
}

//각 테스트 케이스마다 "Case #x: A + B = C" 형식으로 출력한다. x는 테스트 케이스 번호이고 1부터 시작하며, C는 A+B이다.
void plus8(){
    int a,b,t;
    int n=0;
    scanf("%d",&t);
    while(t--){
        n++;
        scanf("%d %d",&a,&b);
        printf("Case #%d: %d + %d = %d\n",n,a,b,a+b);
    }
}
//입력이 주어진다. 입력은 최대 100줄로 이루어져 있고, 알파벳 소문자, 대문자, 공백, 숫자로만 이루어져 있다. 각 줄은 100글자를 넘지 않으며, 빈 줄은 주어지지 않는다. 또, 각 줄은 공백으로 시작하지 않고, 공백으로 끝나지 않는다.
void prin1(){
    char s[101];
    
    while(scanf("%[^\n]\n", s)==1){
        printf("%s\n",s);
    }
}

//공백포함해서 똑같이 출력하기
void prin2(){
    char c;
    while ((c = getchar()) && c != EOF) {
        printf("%c",c);
    }
}

// 각자리수의 합 구하기
void sum(){
    int N, sum=0;
    scanf("%d",&N);
    int a;
    while(N--){
        scanf("%1d",&a);
        sum += a;
    }
    printf("%d",sum);
}

//알파벳 소문자와 대문자로만 이루어진 길이가 N인 단어가 주어진다. 한 줄에 10글자씩 끊어서 출력하는 프로그램을 작성하시오.
char c[100];
void prin10(){
    while (scanf("%10s",c)==1) {
        printf("%s\n",c);
    }
}
//자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
void Nfrom1(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("%d\n",i);
    }
}
void Nto1(){
    int n;
    scanf("%d",&n);
    for(int i=n;i>=1;i--){
        printf("%d\n",i);
    }
}
//N을 입력받은 뒤, 구구단 N단을 출력하는 프로그램을 작성하시오. 출력 형식에 맞춰서 출력하면 된다.
void gugudan(){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=9;i++){
        printf("%d * %d = %d\n",N,i,N*i);
    }
}
//오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

void date(){
    enum Days { SUN,MON,TUES,WEDN,THU,FRI,SAT};


}

//n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.
void sum1N(){
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    printf("%d",sum);
}

//N개의 정수가 주어진다. 이 때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
void maxnum(){
    int n,a,max=0x80000000,min=0x7fffffff;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a>max)max=a;
        if(a<min)min=a;
    }
    printf("%d %d",min,max);
}
//    첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제
void star1(){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}
//첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제 하지만, 오른쪽을 기준으로 정렬한 별 (예제 참고)을 출력하시오.
void star2(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=n-i){
                printf(" ");
            }else{ printf("*");}
        }
        printf("\n");
    }
}
//첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제
void star3(){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        for(int j=N;j>=i;j--){
            printf("*");
        }
        printf("\n");
    }
}
//첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제 하지만, 오른쪽을 기준으로 정렬한 별 (예제 참고)을 출력하시오.
void star4(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=n;j>0;j--){
            if(j<=n-i){
                printf("*");
            }else{ printf(" ");}
        }
        printf("\n");
    }
}
//첫째 줄에는 별 1개, 둘째 줄에는 별 3개, ..., N번째 줄에는 별 2*N-1개를 찍는 문제 별은 가운데를 기준으로 대칭이어야 한다.
void star5(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+i-1;j++){
            if(j<=n-i){printf(" ");
            } else printf("*");
        }
        printf("\n");
    }
}
////첫째 줄에는 별 1개, 둘째 줄에는 별 3개, ..., N번째 줄에는 별 2*N-1개를 찍는 문제 별은 가운데를 기준으로 대칭이어야 한다.
//다이아온드모양
void star6(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+i-1;j++){
            if(j<=n-i){printf(" ");
            } else printf("*");
        }
        printf("\n");
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=n+i-1;j++){
            if(j<=n-i){printf(" ");
            } else printf("*");
        }
        printf("\n");
    }
}
void star7(){
    int n;
    scanf("%d",&n);
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=2*n;j++){
            if(j<=n-i||j>n+i){printf("*");
            } else printf(" ");
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=2*n;j++){
            if(j<=n-i||j>n+i){printf("*");
            } else printf(" ");
        }
        printf("\n");
    }
}
void star8(){
    int n;
    scanf("%d",&n);
    for(int i=n;i>1;i--){
        for(int j=1;j<=n+i-1;j++){
            if(j<=n-i){printf(" ");
            } else printf("*");
        }
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+i-1;j++){
            if(j<=n-i){printf(" ");
            } else printf("*");
        }
        printf("\n");
    }
    
}
void star9(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=n-i){printf(" ");
            } else printf("*");
        }
        printf("\n");
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(j<=n-i){printf(" ");
            } else printf("*");
        }
        printf("\n");
    }
}
void star10(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=n-i){printf(" ");
            } else printf("* ");
        }
        printf("\n");
    }
}
void star11(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2*i-1;j++){
            printf("%d",j);
        }
        printf("\n");
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    star11();
    return 0;
}
