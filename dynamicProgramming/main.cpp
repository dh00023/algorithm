//
//  main.cpp
//  dynamicProgramming
//
//  Created by dahye Jeong on 2017. 6. 23..
//  Copyright © 2017년 dahye Jeong. All rights reserved.
//

#include <iostream>
using namespace std;
/*
 상근이와 선영이가 다른 사람들이 남매간의 대화를 듣는 것을 방지하기 위해서 대화를 서로 암호화 하기로 했다. 그래서 다음과 같은 대화를 했다.
 
 상근: 그냥 간단히 암호화 하자. A를 1이라고 하고, B는 2로, 그리고 Z는 26으로 하는거야.
 선영: 그럼 안돼. 만약, "BEAN"을 암호화하면 25114가 나오는데, 이걸 다시 글자로 바꾸는 방법은 여러가지가 있어.
 상근: 그렇네. 25114를 다시 영어로 바꾸면, "BEAAD", "YAAD", "YAN", "YKD", "BEKD", "BEAN" 총 6가지가 나오는데, BEAN이 맞는 단어라는건 쉽게 알수 있잖아?
 선영: 예가 적절하지 않았네 ㅠㅠ 만약 내가 500자리 글자를 암호화 했다고 해봐. 그 때는 나올 수 있는 해석이 정말 많은데, 그걸 언제 다해봐?
 상근: 얼마나 많은데?
 선영: 구해보자!
 어떤 암호가 주어졌을 때, 그 암호의 해석이 몇 가지가 나올 수 있는지 구하는 프로그램을 작성하시오.
 
 첫째 줄에 5000자리 이하의 암호가 주어진다.
 */
int d[5001];
int mod = 1000000;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    d[0] = 1;
    for (int i=1; i<=n; i++) {
        int x = s[i] - '0';
        if (1 <= x && x <= 9) {
            d[i] += d[i-1];
            d[i] %= mod;
        }
        if (i==1) {
            continue;
        }
        if (s[i-1] == '0') {
            continue;
        }
        x = (s[i-1]-'0')*10 + (s[i]-'0');
        if (10 <= x && x <= 26) {
            d[i] += d[i-2];
            d[i] %= mod;
        }
    }
    cout << d[n] << '\n';
    return 0;
}
