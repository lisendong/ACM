/*
ID: lisendo1
PROG: game1 
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
ifstream in("game1.in"); 
ofstream out("game1.out");
int N;
int data[110];
int sum[110][110];
int dp[110][110];
int main()
{
    in >> N;
    int i, j, k;
    for (i = 0; i < N; i++) {
        in >> data[i]; 
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            int total = 0;
            for (k = i; k <= j; k++) {
                total += data[k];
            }
            sum[i][j] = total;
        }
    }
    for (i = 0; i < N; i++) {
        dp[i][i] = data[i];
    }
    int intval;
    for (intval = 1; intval <= N - 1; intval++) {
        for (i = 0; i < N; i++) {
            j = i + intval;
            if (j >= N) break;
            dp[i][j] = max(data[i] + sum[i+1][j] - dp[i+1][j], data[j] +sum[i][j - 1] - dp[i][j - 1]);
        }
    }
    out << dp[0][N - 1] << " " << sum[0][N - 1] - dp[0][N - 1] << endl;
    return 0;
}

