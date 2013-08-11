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
int p[10010];
int t, n, m;
bool fcmp(int a, int b) {
    return a > b;
}
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int i, j;
        for (i = 0; i < m; i++) {
            cin >> p[i];
        }
        vector<int> c[110];
        for (i = 0; i < n; i++) {
            int num;
            cin >> num;
            for (j = 0; j < num; j++) {
                int tmp;
                cin >> tmp;
                c[i].push_back(tmp);
            }
            sort(c[i].begin(), c[i].end());
        }
        unsigned long long result = 0;
        for (i = 0; i < m; i++) {
            int len = c[p[i]].size();
            if (len == 0) continue;
            result += c[p[i]][len-1];
            c[p[i]].pop_back();
        }
        cout << result << endl;
    }
}



