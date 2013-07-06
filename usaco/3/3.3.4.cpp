/*
ID: lisendo1
PROG: range
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<assert.h>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#define oo 0x7FFFFFF
using namespace std;
ifstream in("range.in"); 
ofstream out("range.out");
int N;
bool data[251][251];
int dp[251][251] = {0};
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    if (c <= a && c <= b) return c;
}
int main()
{
    in >> N;
    int i, j;
    char ch;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            in >> ch;
            if (ch == 10) in >> ch;
            data[i][j] = (ch == '1');
        }
    }
    for (i = N - 1; i >= 0; i--) {
        for (j = N - 1; j >= 0; j--) {
            if (i == N - 1 || j == N - 1) {
                dp[i][j] = (data[i][j] == 1);
            }
            else {
                if (data[i][j] == 1)
                dp[i][j] = min(dp[i + 1][j], dp[i][j+1], dp[i+1][j+1]) + 1;
                else
                dp[i][j] = 0;
            }
        }
    }
    int result[300] = {0};
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (dp[i][j] > 0) {
                for (int k = 2; k <= dp[i][j]; k++) {
                    result[k] ++;
                }
            }
        }
    }
    for (i = 2; i < 255; i++) {
        if (result[i] > 0) out << i << " " << result[i] << endl;
    }
    return 0;
}

