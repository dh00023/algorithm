#include <iostream>
#include <string>
using namespace std;

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
    //star11();a
    
    return 0;
}
