/*
ID: lisendo1
PROG: inflate
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#define oo 100000
#define MAXN 10010
using namespace std;
ifstream in("inflate.in"); 
ofstream out("inflate.out");
int dp1[MAXN] = {0};
int dp2[MAXN] = {0};
int score[MAXN], cost[MAXN];
int main()
{
    int M, N;
    in >> M >> N; 
    int i;
    for (i = 0; i < N; i++) {
        in >> score[i] >> cost[i];
    }
    for (i = 1; i <= M; i++) {
        dp1[i] = i / cost[0] * score[0];
    }
    for (i = 1; i < N; i++) {
        int j;
        for (j = 0; j < cost[i]; j++) {
            dp2[j] = dp1[j];
        }
        for (j = cost[i]; j <= M; j++) {
            dp2[j] = max(dp1[j], score[i] + dp2[j - cost[i]]);
            //for (int k = 1; k * cost[i] <= j; k++) {
            //    dp2[j] = max(dp2[j], score[i] * k + dp1[j - k * cost[i]]);
            //}
        }
        for (j = 0; j <= M; j++) dp1[j] = dp2[j];
    }
    out << dp1[M] << endl; 
}

