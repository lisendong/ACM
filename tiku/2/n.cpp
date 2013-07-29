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
struct work {
    double time, fine;
    int num;
};
work w[2000];
int cmp(work a, work b) {
    if (a.fine / a.time > b.fine / b.time) return 1;
    else if (a.fine / a.time == b.fine / b.time) {
        if (a.num < b.num) return 1;
    }
    return 0;
}
int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int i;
        for (i = 0; i < n; i++) {
            cin >> w[i].time >> w[i].fine;
            w[i].num = i+1;
        }
        sort(w, w+n, cmp);
        for (i = 0; i < n; i++) {
            cout << w[i].num;
            if (i != n - 1) cout << " ";
        }
        cout << endl;
        if (t!=0) cout << endl;
    }
}



