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
double c[3010];
int main()
{
    double anp1, a0;
    int n;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a0 >> anp1;
        int i;
        for (i = 1; i <= n; i++) {
            cin >> c[i];
        }
        double part1 = 0;
        for (i = 1; i <= n; i++) {
            part1 += (n + 1 - i) * c[i];
        }
        double a1 = (anp1 - a0 - 2 * part1) / (n + 1) + a0;
        printf("%.2lf\n\n", a1);
    }
}



