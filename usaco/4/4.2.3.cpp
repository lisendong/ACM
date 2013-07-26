/*
ID: lisendo1
PROG: job
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
#define MAXN 1000
#define nil -1
int cap[MAXN][MAXN] = {0};
#define oo 100000000
using namespace std;
ifstream in("job.in"); 
ofstream out("job.out");
int da[40], db[40], a[40], b[40], resulta[1010], resultb[1010];
int main()
{
    int N, A, B;
    in >> N >> A >> B;
    int i;
    for (i = 1; i <= A; i++) {
        in >> a[i];
        da[i] = a[i];
    }
    for (i = 1; i <= B; i++) {
        in >> b[i];
        db[i] = b[i];
    }
    for (i = 1; i <= N; i++) {
        int min = oo;
        int min_i = oo;
        for (int j = 1; j <= A; j++) {
            if (da[j] < min) {
                min = da[j];
                min_i = j;
            }
        }
        resulta[i] = min;
        da[min_i] += a[min_i];
    }
    for (i = 1; i <= N; i++) {
        int min = oo;
        int min_i = oo;
        for (int j = 1; j <= B; j++) {
            if (db[j] < min) {
                min = db[j];
                min_i = j;
            }
        }
        resultb[i] = min;
        db[min_i] += b[min_i];
    }
    out << resulta[N] << " ";
    int result = 0;
    for (i = 1; i <= N; i++) {
        int tmp = resulta[i] + resultb[N - i + 1];
        if (tmp > result) result = tmp;
    }
    out << result << endl;
}


