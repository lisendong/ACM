/*
ID: lisendo1
PROG: prime3
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
#include<map>
#include<vector>
#define MAXN 200
#define nil -1
#define oo 100000000.0
using namespace std;
int a[100], b[100];
int len1 = 0, len2 = 0;
long long sum = 0;
long long dp[100][10];
void dfs(int step, bool flagdown, bool flagup) {
    int i, j;
    if (step < 0) {
        sum += dp[0][0];
        return;
    }
    if (flagdown && flagup) {
        if (a[step] == b[step]) {
            for (i = 0; i < 10; i++) dp[step][i] = 0;
            for (i = 0; i < 10; i++) dp[step][(i + a[step]) % 10] += dp[step+1][i];
            dfs(step - 1, 1, 1);
        }
        else if (a[step] < b[step]) {
            for (i = 0; i < 10; i++) dp[step][i] = 0;
            for (i = 0; i < 10; i++) dp[step][(i + a[step]) % 10] += dp[step+1][i];
            dfs(step-1, 1, 0);     
            for (i = 0; i < 10; i++) dp[step][i] = 0;
            for (i = 0; i < 10; i++) dp[step][(i + b[step]) % 10] += dp[step+1][i];
            dfs(step-1, 0, 1);
            if (b[step] - a[step] >= 2) {
                for (i = 0; i < 10; i++) dp[step][i] = 0;
                for (j = a[step]+1; j < b[step]; j++) {
                    for (i = 0; i < 10; i++) {
                        dp[step][(i + j) % 10] += dp[step+1][i];
                    }
                }
                dfs(step-1, 0, 0);
            }
        }
    }
    else if (flagdown && !flagup) {
        for (i = 0; i < 10; i++) dp[step][i] = 0;
        for (i = 0; i < 10; i++) dp[step][(i + a[step]) % 10] += dp[step+1][i];
        dfs(step - 1, 1, 0);
        for (i = 0; i < 10; i++) dp[step][i] = 0;
        if (a[step] < 9) {
            for (j = a[step]+1; j < 10; j++) {
                for (i = 0; i < 10; i++) {
                    dp[step][(i + j) % 10] += dp[step+1][i];
                }
            }
            dfs(step-1, 0, 0);
        }
    }
    else if (!flagdown && flagup) {
        for (i = 0; i < 10; i++) dp[step][i] = 0;
        for (i = 0; i < 10; i++) dp[step][(i + b[step]) % 10] += dp[step+1][i];
        dfs(step - 1, 0, 1);
        for (i = 0; i < 10; i++) dp[step][i] = 0;
        if (b[step] > 0) {  //脮芒脌茂脳垄脪芒脢脟b[step]虏禄脢脟a[step]!!!!!   脳垄脪芒脢脟 >0, 虏禄脢脟 >1
            for (j = b[step]-1; j >= 0; j--) {
                for (i = 0; i < 10; i++) {
                    dp[step][(i + j) % 10] += dp[step+1][i];
                }
            }
            dfs(step-1, 0, 0);
        }
    }
    else if (!flagdown && !flagup) {
        for (i = 0; i < 10; i++) dp[step][i] = 0;
        for (j = 0; j < 10; j++) {
            for (i = 0; i < 10; i++) {
                dp[step][(i + j) % 10] += dp[step+1][i];
            }
        }
        dfs(step-1, 0, 0);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int o = 1; o <= t; o++) {
        long long left, right;
        scanf("%I64d%I64d", &left, &right);
        len1 = 0;
        len2 = 0;
        sum = 0;
        int i, j;
        for (i = 0; i < 100; i++) {
            a[i] = 0; b[i] = 0;
            for (j = 0; j < 10; j++) {
                dp[i][j] = 0;
            }
        }
        if (right == 0) {
            //cout << "Case #" << o << ": 1" << endl;
            printf("Case #%d: %I64d\n", o, 1);
            continue;
        }
        while (left) {
            a[len1++] = left % 10;
            left /= 10;
        }
        while (right) {
            b[len2++] = right % 10;
            right /= 10;
        }
        i = max(len1, len2) - 1;
        dp[i+1][0] = 1;
        dfs(i, 1, 1); 
        //cout << "Case #" << o << ": " << sum << endl;
        printf("Case #%d: %I64d\n", o, sum);
    }
}
