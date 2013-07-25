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
int mmin;
int T, m, k;
int turn[10][10];
int heat[10][10];
int min_heat = oo;
vector<int> tube;
int mylog(int a) {
    int result = 0;
    if (a % 2 != 0) {
        result ++;
        a --;
    }
    while (a > 1) {
        a /= 2;
        result ++;
    }
    return result;
}
void dfs(int cur_heat) {
    //cout << cur_heat << endl;
    int i, j;
    if (tube.size() == 1) {
        if (cur_heat < mmin) mmin = cur_heat;
        return;
    }
    if (cur_heat + mylog(tube.size()) * min_heat > mmin) return;
    //cout << tube.size() << ":" << mylog(tube.size()) << endl;
    for (i = 0; i < tube.size(); i++) {
        for (j = i + 1; j < tube.size(); j++) {
            int t1 = tube[i];
            int t2 = tube[j];
            int produce_heat = heat[t1][t2];
            int produce_type = turn[t1][t2];
            vector<int> tmp = tube;
            tube.erase(tube.begin() + i);
            tube.erase(tube.begin() + j - 1);
            tube.push_back(produce_type);
            dfs(cur_heat + produce_heat);
            tube = tmp;
            //tube.pop_back();
            //tube.push_back(t1);
            //tube.push_back(t2);
            //tube.insert(tube.begin() + i, t1);
            //tube.insert(tube.begin() + j, t2);
        }
    }
    
}
int main()
{
    scanf("%d", &T);
    while (T--) {
        min_heat = oo;
        scanf("%d", &m);
        int i, j;
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= m; j++) {
                scanf("%d", &turn[i][j]);
                scanf("%d", &heat[i][j]);
                if (heat[i][j] < min_heat) min_heat = heat[i][j];
            }
        }
        scanf("%d", &k);
        tube.clear();
        mmin = oo;
        for (i = 1; i <= k; i++) {
            scanf("%d", &j);
            tube.push_back(j);
        }
        dfs(0);
        cout << mmin << endl;
        getchar();
        getchar();
    }
}


