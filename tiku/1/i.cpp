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
#include<deque>
#include<list>
#include<vector>
#define oo 0x7FFFFFF
#define MAXN 25
using namespace std;
int f[10010] = {0};
int r[10010] = {0};
int lis_f[10010] = {0};
int lis_r[10010] = {0};
int tmpf[10010] = {0};
int tmpr[10010] = {0};
int main()
{
    int N;
    while (cin >> N) {
        int i;
        for (i = 0; i < N; i++) {
            cin >> f[i];
            r[N - i - 1] = f[i];
        }
        int max = 0;
        for (i = 0; i < 10010; i++) {
            lis_f[i] = oo;
            lis_r[i] = oo;
        }
        for (i = 0; i < N; i++) {
            int x, y;
            x = lower_bound(lis_f, lis_f+ N, f[i]) - lis_f;
            lis_f[x] = f[i];
            tmpf[i] = x + 1;
            y = lower_bound(lis_r, lis_r+ N, r[i]) - lis_r;
            lis_r[y] = r[i];
            tmpr[i] = y + 1;
        }
        for (i = 0; i < N; i++) {
            if (min(tmpf[i], tmpr[N-i-1]) * 2 - 1 > max) max = min(tmpf[i], tmpr[N-i-1]) * 2 - 1;
        }
        cout << max << endl;
    }
}


