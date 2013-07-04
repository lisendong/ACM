/*
ID: lisendo1
PROG: stamps
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#define oo 3000000
#define MAXN 10010
using namespace std;
ifstream in("stamps.in"); 
ofstream out("stamps.out");
short dp[oo] = {0};
int stamps[60];
int main()
{
    int K, N;
    in >> K >> N;
    int i;
    for (i = 0; i < N; i++) {
        in >> stamps[i];
    }
    for (i = 1; ; i++) {
        int min_num = oo, num;
        int j;
        for (j = 0; j < N; j++) {
            if (stamps[j] <= i && dp[i - stamps[j]] + 1 <= K) {
                num = dp[i - stamps[j]] + 1;
                if (num < min_num) min_num = num; 
            }
        }
        if (min_num == oo) break;
        dp[i] = min_num;
    }
    out << i - 1 << endl;
    return 0;
}

