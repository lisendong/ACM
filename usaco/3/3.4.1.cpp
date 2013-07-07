/*
ID: lisendo1
PROG:  fence4
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
#define oo 0x7FFFFFF
#define MAXN 210
using namespace std;
ifstream in("fence4.in"); 
ofstream out("fence4.out");
struct point {
    double x, y;
};
point p[MAXN];
struct line{
    point a, b;
};
line l[MAXN];
double kx, ky;
//bool can_see[MAXN];
int N;
double cross_product(point a, point b, point c) {
    double x1 = b.x - a.x, y1 = b.y - a.y;
    double x2 = c.x - a.x, y2 = c.y - a.y;
    return x1 * y2 - x2 * y1;
}
bool in_range(point c, point a, point b) {
    if (a.x < b.x) swap(a.x, b.x);
    if (a.y < b.y) swap(a.y, b.y);
    if (c.x >= b.x && c.x <= a.x && c.y >= b.y && c.y <= a.y) return true;
    return false;
}
bool intersect(line i, line j) {
    double a1 = cross_product(i.a, i.b, j.a), a2 = cross_product(i.a, i.b, j.b);
    double a3 = cross_product(j.a, j.b, i.a), a4 = cross_product(j.a, j.b, i.b);
    //if (a1 * a2 * a3 * a4 == 0) return true;
    if (a1 == 0 && in_range(j.a, i.a, i.b)) return true;
    if (a2 == 0 && in_range(j.b, i.a, i.b)) return true;
    if (a3 == 0 && in_range(i.a, j.a, j.b)) return true;
    if (a4 == 0 && in_range(i.b, j.a, j.b)) return true;
    if (a1 * a2 < 0 && a3 * a4 < 0) return true;
    return false;
        
}
bool can_watch(double x1, double y1, double x2, double y2, int line_num) {
    if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) < 0.000025) return false;
    line mid;
    mid.a.x = kx; mid.a.y = ky;
    mid.b.x = (x1 + x2) / 2; mid.b.y = (y1 + y2) / 2; 
    bool temp = true; //flag
    int i;
    for (i = 0; i < N; i++) {
        if (i != line_num && intersect(mid, l[i])) {
            //cout << line_num << " was covered by " << i << endl;
            temp = false;
            break;
        }
    }
    if (temp == true) return temp;
    temp = can_watch(mid.b.x, mid.b.y, x2, y2, line_num);
    if (temp == true) return temp;
    temp = can_watch(mid.b.x, mid.b.y, x1, y1, line_num);
    return temp; 
}
int main()
{
    in >> N;
    int i, j;
    in >> kx >> ky;
    for (i = 0; i < N; i++) {
        in >> p[i].x >> p[i].y;
    }
    point see;
    see.x = kx; see.y = ky;
    l[0].a = p[0]; l[0].b = p[N - 1];
    for (i = 1; i < N; i++) {
        l[i].a = p[i - 1]; l[i].b = p[i];
    }
    //judge if there is any two segment intersect
    for (i = 0; i < N; i++) {
        for (j = i + 2; j < N; j++) {
            if (i == 0 && j == N - 1) continue;
            if (intersect(l[i], l[j])) {
                //cout << l[i] << endl;
                //cout << l[j] << endl;
                cout << i << "," << j << endl;
                out << "NOFENCE" << endl;
                return 0;
            }
        }
    }
    bool flag[MAXN] = {0};
    int sum = 0;
    for (i = 0; i < N; i++) {
        if (cross_product(see, l[i].a, l[i].b) == 0) continue;
        if (can_watch(l[i].a.x, l[i].a.y, l[i].b.x, l[i].b.y, i)) {flag[i] = true; sum ++;}
    }
    out << sum << endl;
    for (i = 1; i <= N - 2; i++) {
        if (flag[i]) out << l[i].a.x << " " << l[i].a.y << " " << l[i].b.x << " " << l[i].b.y << endl;
    }
    i = 0;
    if (flag[i]) out << l[i].a.x << " " << l[i].a.y << " " << l[i].b.x << " " << l[i].b.y << endl;
    i = N - 1;
    if (flag[i]) out << l[i].a.x << " " << l[i].a.y << " " << l[i].b.x << " " << l[i].b.y << endl;
    return 0;
}

