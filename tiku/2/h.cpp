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
int a[200][200];
int N;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        int i, j;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                scanf("%d", &a[i][j]);
                a[i+N][j] = a[i][j];
                a[i][j+N] = a[i][j];
                a[i+N][j+N] = a[i][j];
            }
        }
        int imax = 0;
        int sum[200][200] = {0};
        int m, n;
        for (m = 0; m < N * 2; m++) {
            for (n = 0; n < N * 2; n++) {
                for (int i = m; i<min(m+N, N*2); i++) {
                    for (int j = n; j < min(n+N,N*2); j++) {
                        if (m==i && n == j) {
                            sum[i][j] = a[i][j];
                            if (sum[i][j] > imax) imax = sum[i][j];
                            continue;
                        }
                        if (m==i) {
                            sum[i][j] = sum[i][j-1] + a[i][j];
                            if (sum[i][j] > imax) imax = sum[i][j];
                            continue;
                        }
                        if (n==j) {
                            sum[i][j] = sum[i-1][j] + a[i][j];
                            if (sum[i][j] > imax) imax = sum[i][j];
                            continue;
                        }
                        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
                        if (sum[i][j] > imax) imax = sum[i][j];
                        continue;

                    }
                }
            }
        }
        cout << imax << endl;
    }
}



