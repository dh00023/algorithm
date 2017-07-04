#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

void alpha() {
    string s;
    cin >> s;
    
    for (int i='a'; i<='z'; i++) {
        cout << count(s.begin(), s.end(), i) << ' ';
    }
    
    cout << '\n';
}

void alpha_loc() {
    string s;
    cin >> s;
    
    for (int i='a'; i<='z'; i++) {
        auto it = find(s.begin(), s.end(), i);
        if (it == s.end()) {
            cout << -1 << ' ';
        } else {
            cout << (it - s.begin()) << ' ';
        }
    }
    cout << '\n';
}

string rot13(string s) {
    for (int i=0; i<s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'm') {
            s[i] = s[i] + 13;
        } else if (s[i] >= 'n' && s[i] <= 'z') {
            s[i] = s[i] - 13;
        } else if(s[i] >= 'A' && s[i] <= 'M') {
            s[i] = s[i] + 13;
        } else if(s[i] >= 'N' && s[i] <= 'Z') {
            s[i] = s[i] - 13;
        }
    }
    return s;
}
void rot13_main() {
    string s;
    getline(cin,s);
    cout << rot13(s) << '\n';
}


void suffix() {
    string s;
    cin>>s;
    int n = s.size();
    vector<int> a;
    for (int i=0; i<n; i++) a.push_back(i);
    sort(a.begin(),a.end(), [&s](int u, int v) {
        return strcmp(s.c_str()+u,s.c_str()+v) < 0;
    });
    for (auto &x : a) {
        cout << s.substr(x) << '\n';
    }
}
