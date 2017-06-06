//
//  main.c
//  test
//
//  Created by dahye Jeong on 2017. 6. 4..
//  Copyright © 2017년 dahye Jeong. All rights reserved.
//

#include <stdio.h>
#include <math.h>
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <math.h>
int solution(int A, int B) {
    // write your code in C++14 (g++ 6.2.0)
    
    int res = sqrt(B)-sqrt(A)+1;
    printf("%d\n",res);
    return res;
}
int main() {
    // insert code here...
    solution(4, 17);
    printf("Hello, World!\n");
    return 0;
}
