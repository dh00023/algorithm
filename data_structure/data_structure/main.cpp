//
//  main.cpp
//  data_structure
//
//  Created by dahye Jeong on 2017. 6. 16..
//  Copyright © 2017년 dahye Jeong. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
 괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.
 
 여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.
 */
string co(string s){
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if (s[i]=='(') {
            cnt+=1;
        }else{
            cnt -=1;
        }
        if(cnt<0) return "NO";
    }
    if(cnt == 0 ) {
        return "YES";
    }else return "NO";
}

void vps(){
    int n;
    scanf("%d",&n);
    while(n--){
        string t;
        cin >> t;
        cout << co(t)<<'\n';
    }
}

/*
 여러 개의 쇠막대기를 레이저로 절단하려고 한다. 효율적인 작업을 위해서 쇠막대기를 아래에서 위로 겹쳐 놓고, 레이저를 위에서 수직으로 발사하여 쇠막대기들을 자른다. 쇠막대기와 레이저의 배치는 다음 조건을 만족한다.
 
 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있다. - 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되, 끝점은 겹치지 않도록 놓는다.
 각 쇠막대기를 자르는 레이저는 적어도 하나 존재한다.
 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않는다.
 아래 그림은 위 조건을 만족하는 예를 보여준다. 수평으로 그려진 굵은 실선은 쇠막대기이고, 점은 레이저의 위치, 수직으로 그려진 점선 화살표는 레이저의 발사 방향이다.
 */
void stick(){
    string t;
    cin >> t;
    int count=0;
    stack<int> s;
    
    for(int i=0;i<t.size();i++){
        if(t[i]=='('){
            s.push(i);
        }else{
            if(s.top()+1==i){
                s.pop();
                count += s.size();
            }else{
                s.pop();
                count+=1;
            }
        }
    }
    printf("%d\n",count);
}
/*
 한 줄로 된 간단한 에디터를 구현하려고 한다. 이 편집기는 영어 소문자만을 기록할 수 있는 편집기로, 최대 600,000글자까지 입력할 수 있다.
 
 이 편집기에는 '커서'라는 것이 있는데, 커서는 문장의 맨 앞(첫 번째 문자의 왼쪽), 문장의 맨 뒤(마지막 문자의 오른쪽), 또는 문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치할 수 있다. 즉 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 경우가 있다.
 
 이 편집기가 지원하는 명령어는 다음과 같다.
 
 L	커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
 D	커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
 B	커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
 삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
 P $	$라는 문자를 커서 왼쪽에 추가함
 초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어졌을 때, 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 구하는 프로그램을 작성하시오. 단, 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다고 한다.
 */
char a[600000];
int main() {
    scanf("%s",a);
    stack<char> left, right;
    int n = strlen(a);
    for (int i=0; i<n; i++) {
        left.push(a[i]);
    }
    int m;
    scanf("%d",&m);
    while (m--) {
        char what;
        scanf(" %c",&what);
        if (what == 'L') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if (what == 'D') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if (what == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        } else if (what == 'P') {
            char c;
            scanf(" %c",&c);
            left.push(c);
        }
    }
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        printf("%c",right.top());
        right.pop();
    }
    printf("\n");
    return 0;
}
