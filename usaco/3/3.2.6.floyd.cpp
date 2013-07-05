/*
ID: lisendo1
PROG: butter 
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<list>
#define MAXN 510
#define MAXP 810
#define oo 300
using namespace std;
ifstream in("butter.in"); 
ofstream out("butter.out");
bool flag[MAXP] = {0};
int cows_num[MAXP] = {0};
int dist[MAXP] = {0};
int dis[MAXP][MAXP];
int N, P, C;
list <int> l[MAXP];
int min_t = oo * 500 * 800;
int SPFA(int s) {
    queue <int> q;
    q.push(s);
    memset(dist, oo, sizeof(dist));
    memset(flag, false, sizeof(flag));
    flag[s] = true;
    dist[s] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        flag[cur] = false;
        //list <int>::iterator i;
        //for (i = l[cur].begin(); i != l[cur].end(); i++) {
        //   if (dist[cur] + dis[cur][*i] < dist[*i]) {
        //       dist[*i] = dist[cur] + dis[cur][*i];
        //       if (!flag[*i]) {q.push(*i); flag[*i] = true;}
        //   }
        //}
        int i;
        for (i = 1; i <= P; i++) {
            if (dis[cur][i] != oo && dis[cur][i] != 0) {
                if (dist[cur] + dis[cur][i] < dist[i]) {
                    dist[i] = dist[cur] + dis[cur][i];
                    if (!flag[i]) {q.push(i); flag[i] = true;}
                }
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= P; i++) {
        if (cows_num[i] > 0) {
            sum += cows_num[i] * dist[i];
        }
    }
    return sum;
}
int djs(int s) {
    int i;
    int sum = 0;
    memset(dist, oo, sizeof(dist));
    memset(flag, false, sizeof(flag));
    flag[s] = true;
    dist[s] = 0;
    for (i = 1; i <= P; i++) {
        if (dis[s][i] != oo && dis[s][i] != 0) {
            dist[i] = dis[s][i];
        }
    }
    for (int count = 1; count <= P - 1; count++) {
        int min_dis = -1, cur;
        for (i = 1; i <= P; i++) {
            if (flag[i] == false && (min_dis == -1 || dist[i] < min_dis)) {
                min_dis = dist[i];
                cur = i;
            }
        }
        flag[cur] = true;
        if (cows_num[cur] > 0) {
            sum += cows_num[cur] * dist[cur];
            if (sum > min_t) return sum;
        }
        int j;
        for (j = 1; j <= P; j++) {
            if (dis[cur][j] != oo && dis[cur][j] != 0) {
                if (dist[cur] + dis[cur][j] < dist[j]) {
                    dist[j] = dist[cur] + dis[cur][j];
                }
            }
        }
    }
    return sum;
}
int main()
{
    int i, j, k;
    in >> N >> P >> C;
    for (i = 0; i < N; i++) {
        int p_num;
        in >> p_num;
        cows_num[p_num] ++;
    }
    memset(dis, oo, sizeof(dis));
    for (i = 0; i < C; i++) {
        int a, b, c;
        in >> a >> b >>c;
        dis[a][b] = c;
        dis[b][a] = c;
    }
    for (i = 1; i <= P; i++) {
        dis[i][i] = 0;
    }
    for (i = 1; i <= P; i++) {
        for (j = 1; j <= P; j++) {
            for (k = 1; k <= P; k++) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    dis[j][i] = dis[i][j];
                }
            }
        }
    }
    for (i = 1; i <= P; i++) {
        int sum = 0;
        for (j = 1; j <= P; j++) {
            //cout << cows_num[j] << ":" << dis[i][j] << endl;
            if (cows_num[j] > 0) sum += cows_num[j] * dis[i][j];
        }
        if (sum < min_t) min_t = sum; 
    }
    out << min_t << endl;
}

