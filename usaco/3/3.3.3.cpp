/*
ID: lisendo1
PROG: camelot
LANG: C++
*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define oo 0x7FFFFFF
using namespace std;
ifstream in("camelot.in"); 
ofstream out("camelot.out");
class myvector {
    public:
        int r, c;
        int dis[40][40]; //shortest path length
};
class myvector v[40][40];
int R, C;
int kx, ky;
int knight[2000][2], knight_num = 0;
int min_step = oo;
int ma[8][2] = {{1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}};
int wang[8][2] = {{1, 1}, {1, -1}, {1, 0}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
int get_step(int row, int col) {
    int min = oo;
    //各走各的
    int i, j;
    int sum = 0;
    for (i = 0; i < knight_num; i++) {
        sum += v[row][col].dis[knight[i][0]][knight[i][1]];
    }
    int king_self_path = max(abs(row - kx), abs(col - ky));
    sum += king_self_path;
    if (sum < min) min = sum;
    int init_sum = sum;
    //到王的位置接走王
    int qishi;
//    for (qishi = 0; qishi < knight_num; qishi++) {
//        sum = init_sum - king_self_path - v[row][col].dis[knight[qishi][0]][knight[qishi][1]];
//        sum += v[kx][ky].dis[knight[qishi][0]][knight[qishi][1]];
//        sum += v[row][col].dis[kx][ky];
//        if (sum < min) min = sum;
//    }
    int wangr, wangc;
    for (i = -2; i <= 2; i++) {
        for (j = -2; j <= 2; j++) {
            wangr = kx + i;
            wangc = ky + j;
            if (wangr < 1 || wangr > R) continue;
            if (wangc < 1 || wangc > C) continue;
            for (qishi = 0; qishi < knight_num; qishi++) {
                sum = init_sum - king_self_path - v[row][col].dis[knight[qishi][0]][knight[qishi][1]];
                sum += v[wangr][wangc].dis[knight[qishi][0]][knight[qishi][1]];
                sum += v[wangr][wangc].dis[row][col];
                sum += max(abs(i), abs(j));
                if (sum < min) min = sum;
            }
        }
    }
    //到王的四周接走王
    return min;
}
int bfs(int row, int col) {
    queue <class myvector *> q;
    class myvector * iself = &(v[row][col]);
    int i, j;
    for (i = 1; i <= R; i++) {
        for (j = 1; j <= C; j++) {
            iself->dis[i][j] = oo;
        }
    }
    iself->dis[row][col] = 0;
    q.push(iself); 
    while (!q.empty()) {
        //cout << q.size() << endl;
        class myvector * cur = q.front();
        q.pop();
        int this_dis = iself->dis[cur->r][cur->c];
        for (i = 0; i <= 7; i++) {
            int newr = cur->r + ma[i][1];
            int newc = cur->c + ma[i][0];
            if (newr < 1 || newr > R) continue;
            if (newc < 1 || newc > C) continue;
            if (iself->dis[newr][newc] == oo) {
                iself->dis[newr][newc] = this_dis + 1;
                //cout << iself->dis[row][col] << endl;
                q.push(&v[newr][newc]);
            }
        }
    }
}
int main()
{
    in >> R >> C;
    int i, j;
    for (i = 1; i <= R; i++) {
        for (j = 1; j <= C; j++) {
            v[i][j].r = i; v[i][j].c = j;
            memset(v[i][j].dis, 0, sizeof(v[i][j].dis));
        }
    }
    in.get();
    char y;
    int x;
    in >> y;
    in >> x;
    kx = x;
    ky = y - 'A' + 1;
    in.get(); 
    while (in >> y >> x) {
        knight[knight_num][0] = x;
        knight[knight_num][1] = y - 'A' + 1;
        knight_num++;
        in.get();
    }
    for(i = 1; i <= R; i++) {
        for (j = 1; j <= C; j++) {
            bfs(i, j);
        }
    }
    for(i = 1; i <= R; i++) {
        for (j = 1; j <= C; j++) {
            int steps = get_step(i, j);
            if (steps < min_step) min_step = steps;
            //cout << i << "," << j << ":" << steps << endl;
        }
    }
    out << min_step << endl;
    return 0;
}

