/*
ID: lisendo1
PROG: kimbits
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#define oo 50
#define MAXN 50
using namespace std;
ifstream in("kimbits.in"); 
ofstream out("kimbits.out");
long long N, L, I;
int dp[MAXN][MAXN] = {0};
int main()
{
    in >> N >> L >> I;
    int i, j;
    for (j = 0; j <= L; j++) {
        dp[0][j] = 1;
    }
    for (i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= L ; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    int onenum = 0;
    for (i = N; i >= 1; i--) {
        //cout << dp[i - 1][L - onenum] << endl;
        if (I > dp[i - 1][L - onenum]) {
            out << 1;
            I -= dp[i - 1][L - onenum];
            onenum++;
        }
        else {
            out << 0;
        }
    }
    out << endl;
    return 0;
}

