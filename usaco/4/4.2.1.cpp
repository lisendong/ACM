/*
ID: lisendo1
PROG: ditch
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
#define MAXN 210
#define nil -1
int cap[MAXN][MAXN] = {0};
#define oo 100000000
using namespace std;
ifstream in("ditch.in"); 
ofstream out("ditch.out");
int N, M;
int maxflow() {
    int result = 0;
    int last_node[210];
    int flow[210];
    int max_flow;
    int max_loc;
    int visit[210];
    while (true) {
        int i;
        for (i = 1; i <= M; i++) {
            last_node[i] = nil;
            flow[i] = 0;
            visit[i] = 0;
        }
        flow[1] = oo;
        while (true) {
            max_flow = 0;
            max_loc = nil;
            for (i = 1; i <= M; i++) {
                if (visit[i] == 0 && flow[i] > max_flow) {
                    max_flow = flow[i];
                    max_loc = i;
                }
            }
            //cout << "maxlock:" << max_loc << "maxflow" << max_flow << endl;
            if (max_loc == nil) break;
            if (max_loc == M) break;
            visit[max_loc] = 1;
            for (i = 1; i <= M; i++) {
                if (flow[i] < min(flow[max_loc], cap[max_loc][i])) {
                    flow[i] = min(flow[max_loc], cap[max_loc][i]);
                    last_node[i] = max_loc;
                }
            }
        }
        if (max_loc == nil) break;
        result += flow[M];
        int cur_node = M;
        while (cur_node != 1) {
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
    in >> N >> M;
    int a, b, c;
    int i;
    for (i = 1; i <= N; i++) {
        in >> a >> b >> c;
        cap[a][b] += c;
    }
    int max_flow = maxflow();
    out << max_flow << endl;
}


