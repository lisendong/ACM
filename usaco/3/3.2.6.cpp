/*
ID: lisendo1
PROG: butter 
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
#define MAXN 510
#define MAXP 810
#define oo 300 * 810
using namespace std;
ifstream in("butter.in"); 
ofstream out("butter.out");
bool flag[MAXP] = {0};
int cows_num[MAXP] = {0};
int dist[MAXP] = {0};
int dis[MAXP][MAXP];
int N, P, C;
list <int> l[MAXP];
int min_t = oo * 500;
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
int parent(int n) {
    return (n - 1) / 2;
}
int left(int n) {
    return n * 2 + 1;
}
int right(int n) {
    return n * 2 + 2;
}
struct vertex {
    int num, w;
};
struct vertex heap[MAXP];
int heap_num = 0, ph[MAXP];
void shift_up(int n) {
    while(n != 0) {
        if (heap[n].w < heap[parent(n)].w) {
            ph[heap[n].num] = parent(n);
            ph[heap[parent(n)].num] = n;
            int tmpw, tmpnum, tmppos;
            tmpw = heap[n].w; tmpnum = heap[n].num; 
            heap[n].w = heap[parent(n)].w;  heap[n].num = heap[parent(n)].num;
            heap[parent(n)].w = tmpw;  heap[parent(n)].num = tmpnum;
            n = parent(n);
        }
        else break;
    }
}
void shift_down(int n) {
    while (n < heap_num) {
        int smaller = heap[n].w, smaller_node = n;
        if (left(n) < heap_num && smaller > heap[left(n)].w) {
            smaller = heap[left(n)].w;
            smaller_node = left(n);
        }
        if (right(n) < heap_num && smaller > heap[right(n)].w) {
            smaller = heap[right(n)].w;
            smaller_node = right(n);
        }
        if (smaller_node == n) break;
        //cout << smaller_node << ":" << heap[smaller_node].num << endl;
        ph[heap[n].num] = smaller_node;
        ph[heap[smaller_node].num] = n;
        int tmpw, tmpnum, tmppos;
        tmpw = heap[n].w; tmpnum = heap[n].num; //tmppos = ph[heap[n].num];
        heap[n].w = heap[smaller_node].w;  heap[n].num = heap[smaller_node].num;
        heap[smaller_node].w = tmpw;  heap[smaller_node].num = tmpnum;
        n = smaller_node;
        //cout << n << endl;
    }
}
int djs(int s) {
    int i;
    int sum = 0;
    for (i = 0; i < MAXP; i++) dist[i] = oo;
    for (i = 0; i < MAXP; i++) flag[i] = false;
    for (i = 0; i < MAXP; i++) ph[i] = -1;
    flag[s] = true;
    dist[s] = 0;
    heap_num = 0;
    for (i = 1; i <= P; i++) {
        if (dis[s][i] != oo && dis[s][i] != 0) {
            dist[i] = dis[s][i];
            heap[heap_num].num = i;
            heap[heap_num].w = dis[s][i];
            ph[i] = heap_num;
            shift_up(heap_num);
            heap_num++;
        }
    }
    for (int count = 1; count <= P - 1; count++) {
        int min_num = -1, min_i = 0;
        for (i = 1; i <= P; i++) {
            if (flag[i] == false && (min_num == -1 || min_num > dist[i])) {
                min_num = dist[i];
                min_i = i;
            }
        }
        int cur = heap[0].num;
        //if (heap_num <= 0) break;
        //assert(min_i == cur);
        //cout << min_i << ":" << cur << "::" << heap[0].w << endl;
        //cout << cur << endl;
        heap_num--;
        ph[cur] = -1;
        heap[0].num = heap[heap_num].num;
        heap[0].w = heap[heap_num].w;
        ph[heap[0].num] = 0;
        shift_down(0);
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
                    if (ph[j] == -1) {
                        heap[heap_num].num = j;
                        heap[heap_num].w = dist[j];
                        ph[j] = heap_num;
                        shift_up(heap_num);
                        heap_num++;
                    }
                    else {
                        heap[ph[j]].w = dist[j];
                        shift_up(ph[j]);
                    }
                }
            }
        }
    }
    return sum;
}
int main()
{
    int i, j;
    in >> N >> P >> C;
    for (i = 0; i < N; i++) {
        int p_num;
        in >> p_num;
        cows_num[p_num] ++;
    }
    for (i = 0; i < MAXP; i++) {
        for (j = 0; j < MAXP; j++) {
            dis[i][j] = oo;
        }
    }
    for (i = 0; i < C; i++) {
        int a, b, c;
        in >> a >> b >> c;
        dis[a][b] = c;
        dis[b][a] = c;
    }
    for (i = 1; i <= P; i++) {
        dis[i][i] = 0;
        for (j = 1; j <= P; j++) {
            if (dis[i][j] != oo && dis[i][j] != 0) {
                l[i].push_back(j);
            }
        }
    }
    for (i = P; i >= 1; i--) {
        int sum = djs(i);
        //cout << i << ":" << sum << endl;
        if (sum < min_t) min_t = sum; 
    }
    out << min_t << endl;
}

