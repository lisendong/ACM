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
#define MAXHP 65535*3+10
#define MAXN 30010
int tree[MAXHP] = {0};
int shibin[MAXN];
using namespace std;
int read(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx, int val) {
    while (idx < MAXHP) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
int bi_search(int rank) {
    int left = 1, right = MAXHP;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (read(mid) < rank) {
            left = mid + 1;
        }
        else 
            right = mid - 1;
    }
    return left;
}
int main()
{
    int N;
    int i;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &shibin[i]);
        update(shibin[i], 1);
    }
    int Q;
    scanf("%d", &Q);
    for (i = 1; i <= Q; i++) {
        char cmd;
        getchar();
        scanf("%c", &cmd);
        if (cmd == 'Q') {
            int rank;
            scanf("%d", &rank);
            if (rank > N) printf("-1\n");
            else {
                rank = N - rank + 1;
                int k;
                k = bi_search(rank);
                printf("%d\n", k);
            }
        }
        else if (cmd == 'A') {
            int x, y;
            scanf("%d %d", &x, &y);
            update(shibin[x], -1);
            shibin[x] -= y;
            if (shibin[x] <= 0) N--;
            else update(shibin[x], 1);
        }
        else if (cmd == 'C') {
            int x, y;
            scanf("%d %d", &x, &y);
            update(shibin[x], -1);
            shibin[x] += y;
            update(shibin[x], 1);
        }
    }
    printf("%d\n", N);
}


