//
//  string.cpp
//  data_structure
//
//  Created by dahye Jeong on 2017. 6. 18..
//  Copyright © 2017년 dahye Jeong. All rights reserved.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cnt[26];
//알파벳 소문자로만 이루어진 단어 S가 주어진다. 이 때, 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.
void alp(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0;i<n;i++){
        cnt[s[i]-97]+=1;
    }
    for(int i=0;i<26;i++){
        printf("%d ",cnt[i]);
    }
}

//알파벳 소문자로만 이루어진 단어 S가 주어진다. 각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.
void alp_loc(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt[26];
    fill_n(cnt, 26, -1);
    for(int i=0;i<n;i++){
        if(cnt[s[i]-97]==-1) cnt[s[i]-97]=i;
    }
    for(int i=0;i<26;i++){
        printf("%d ",cnt[i]);
    }
}
//문자열 N개가 주어진다. 이 때, 문자열에 포함되어 있는 소문자, 대문자, 숫자, 공백의 개수를 구하는 프로그램을 작성하시오. 각 문자열은 알파벳 소문자, 대문자, 숫자, 공백으로만 이루어져 있다.
void count_s(){
    string s;
    while(getline(cin, s)){
        int upper=0,lower=0,number=0,space=0;
        for(int i=0;i<s.size();i++){
            if('a'<=s[i]&&s[i]<='z'){
                lower+=1;
            }else if('A'<=s[i]&&s[i]<='Z'){
                upper+=1;
            }else if('0'<=s[i]&&s[i]<='9'){
                number+=1;
            }else if(s[i]==' ') space+=1;
        }
        printf("%d %d %d %d\n",lower,upper,number,space);
    }
    
}
//알파벳으로만 이루어진 단어를 입력받아, 그 길이를 출력하는 프로그램을 작성하시오.
void len_s(){
    string s;
    cin >> s;
    printf("%lu",s.length());
}

/*
 ROT13은 카이사르 암호의 일종으로 영어 알파벳을 13글자씩 밀어서 만든다.
 
 예를 들어, "Baekjoon Online Judge"를 ROT13으로 암호화하면 "Onrxwbba Bayvar Whqtr"가 된다. ROT13으로 암호화한 내용을 원래 내용으로 바꾸려면 암호화한 문자열을 다시 ROT13하면 된다. 앞에서 암호화한 문자열 "Onrxwbba Bayvar Whqtr"에 다시 ROT13을 적용하면 "Baekjoon Online Judge"가 된다.
 
 ROT13은 알파벳 대문자와 소문자에만 적용할 수 있다. 알파벳이 아닌 글자는 원래 글자 그대로 남아 있어야 한다. 예를 들어, "One is 1"을 ROT13으로 암호화하면 "Bar vf 1"이 된다.
 
 문자열이 주어졌을 때, "ROT13"으로 암호화한 다음 출력하는 프로그램을 작성하시오.
 */

void rot13(){
    string s;
    getline(cin, s);
    for(int i=0;i<s.size();i++){
        if('a'<=s[i]&&s[i]<='z'){
            printf("%c",97+(s[i]+13-97)%26);
        }else if('A'<=s[i]&&s[i]<='Z'){
            printf("%c",65+(s[i]+13-65)%26);
        }else printf("%c",s[i]);
    }
    printf("\n");
}
//네 자연수 A, B, C, D가 주어진다. 이 때, A와 B를 붙인 수와 C와 D를 붙인 수의 합을 구하는 프로그램을 작성하시오. 두 수 A와 B를 합치는 것은 A의 뒤에 B를 붙이는 것을 의미한다. 즉, 20과 30을 붙이면 2030이 된다.
void abcd(){
    string a,b,c,d;
    cin >> a>>b>>c>>d;
    
    printf("%lld",stoll(a+b)+stoll(c+d));
}
/*
 접미사 배열은 문자열 S의 모든 접미사를 사전순으로 정렬해 놓은 배열이다.
 
 baekjoon의 접미사는 baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n 으로 총 8가지가 있고, 이를 사전순으로 정렬하면, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon이 된다.
 
 문자열 S가 주어졌을 때, 모든 접미사를 사전순으로 정렬한 다음 출력하는 프로그램을 작성하시오.
 
 */

void suffix(){
    string s,str;
    cin >> s;
    vector<string> abc;
    for(int i=0;i<s.size();i++){
        abc.push_back(str.assign(s,i,s.size()));
    }
    sort(abc.begin(), abc.end());
    for(int t=0;t<abc.size();++t){
        cout<<abc.at(t)<<'\n';
    }
}

