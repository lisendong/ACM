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
struct jogger{
    int a, b;
};
jogger j[1010];
bool cmp(jogger a, jogger b) {
    if (a.a > b.a) return 1;
    if (a.a == b.a && a.b <= b.b) return 1;
    return 0;
}
int cnt(bool iset[], int left, int right) {
    int sum = 0;
    for (int i = left; i <= right; i++) {
        if (iset[i]) sum++;
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int K, N;
        //cin >> K >> N;
        scanf("%d%d", &K, &N);
        int i;
        for (i = 0; i < N; i++) {
            //cin >> j[i].a >> j[i].b;
            scanf("%d%d", &j[i].a, &j[i].b);
            j[i].a += 10000;
            j[i].b += 10000;
            if (j[i].b < j[i].a) {
                int tmp = j[i].b;
                j[i].b = j[i].a;
                j[i].a = tmp;
            }
        }
        sort(j, j+N, cmp);
        bool iset[20020] = {0};
        for (i = 0; i < N; i++) {
            int cur = cnt(iset, j[i].a, j[i].b);
            if (cur >= K) continue;
            int k;
            for (k = j[i].a; cur < K && k <= j[i].b; k++) {
                if (iset[k] == false) {
                    iset[k] = true;
                    cur++;
                }
            }
        }
        int total = cnt(iset, 0, 20000);
        printf("%d\n", total);
        for (i = 0; i < 20020; i++) {
            if (iset[i]) printf("%d\n", i-10000);
        }
        if (t!=0) printf("\n");
    }
}



