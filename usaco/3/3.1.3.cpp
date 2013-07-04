/*
ID: lisendo1
PROG: humble
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
#define MAXK 110
#define MAXN 100010
using namespace std;
ifstream in("humble.in"); 
ofstream out("humble.out");
int prime[MAXK];
int result[MAXN];
int hindex[MAXK] = {0};
int main()
{
    int K, N;
    in >> K >> N; 
    int i;
    for (i = 0; i < K; i++) {
        in >> prime[i];
    }
    result[0] = 1;
    for (i = 1; i <= N; i++) {
        int j;
        int tmp[MAXK];
        for (j = 0; j < K; j++) {
            int k;
            for (k = hindex[j]; result[k] * prime[j] <= result[i - 1]; k++);
            tmp[j] = result[k] * prime[j];
            hindex[j] = k;
        }
        sort(tmp, tmp + K);
        result[i] = tmp[0];
    }
    out << result[N] << endl;
}

