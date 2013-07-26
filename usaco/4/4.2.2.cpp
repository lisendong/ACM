/*
ID: lisendo1
PROG: stall4
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
ifstream in("stall4.in"); 
ofstream out("stall4.out");
int N, M;
int maxflow() {
    int result = 0;
    int last_node[MAXN];
    int flow[MAXN];
    int max_flow;
    int max_loc;
    int visit[MAXN];
    while (true) {
        int i;
        for (i = 0; i <= M; i++) {
            last_node[i] = nil;
            flow[i] = 0;
            visit[i] = 0;
        }
        flow[0] = oo;
        while (true) {
            max_flow = 0;
            max_loc = nil;
            for (i = 0; i <= M; i++) {
                if (visit[i] == 0 && flow[i] > max_flow) {
                    max_flow = flow[i];
                    max_loc = i;
                }
            }
            //cout << "maxlock:" << max_loc << "maxflow" << max_flow << endl;
            if (max_loc == nil) break;
            if (max_loc == M) break;
            visit[max_loc] = 1;
            for (i = 0; i <= M; i++) {
                if (flow[i] < min(flow[max_loc], cap[max_loc][i])) {
                    flow[i] = min(flow[max_loc], cap[max_loc][i]);
                    last_node[i] = max_loc;
                }
            }
        }
        if (max_loc == nil) break;
        result += flow[M];
        int cur_node = M;
        while (cur_node != 0) {
            cap[last_node[cur_node]][cur_node] -= flow[M];
            cap[cur_node][last_node[cur_node]] += flow[M];
            cur_node = last_node[cur_node];
        }
        //cout << result << endl;
    }
    return result;
}
int main()
{
    int n, m;
    in >> n >> m;
    M = n + m + m + 1;
    int i;
    for (i = 1; i <= n; i++) {
        int a;
        in >> a;// >> b >> c;
        for (int  j = 1; j <= a; j++) {
            int tmp;
            in >> tmp;
            cap[i][tmp + n] = 1;
        }
        //cap[a][b] += c;
    }
    for (i = 1; i <= n; i++) {
       cap[0][i] = 1;
    }
    for (i = n + 1; i <= n + m; i++) {
        cap[i][i+m] = 1;
    }
    for (i = n + m + 1; i <= n + m + m; i++) {
        cap[i][M] = oo;
    }
    int max_flow = maxflow();
    out << max_flow << endl;
}


