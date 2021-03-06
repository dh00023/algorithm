#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
/*
 n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 숫자를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 숫자는 한 개 이상 선택해야 한다.
 
 예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.
 첫째 줄에 정수 n(1≤n≤100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.
 */
int d[100001]; // a[i]로 끝나는 최대 연속 합
int main() {
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    d[0]=a[0];
    int ans = d[0];

    for(int i=1;i<n;i++){
        d[i]=max(d[i-1]+a[i],a[i]);
        if(ans < d[i]) ans = d[i];
    }
    
    printf("%d",ans);
    return 0;
}
