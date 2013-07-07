/*
ID: lisendo1
PROG: fence9
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
ifstream in("fence9.in"); 
ofstream out("fence9.out");
struct point {
    double x, y;
};
struct line {
    point a, b;
};
point p1, p2, p3;
line l1, l2, l3;
point mid;
double n, m, p;
double k, b;
bool cp(line l, double x, double y) {
    double x1, y1, x2, y2;
    x1 = x - l.a.x; y1 = y - l.a.y;
    x2 = l.b.x - l.a.x; y2 = l.b.y - l.a.y;
    double a1 = x1 * y2 - y1 * x2;
    x1 = mid.x - l.a.x; y1 = mid.y - l.a.y;
    double a2 = x1 * y2 - y1 * x2;
    if (a1 * a2 > 0) return true;
    else return false;
}
bool check(double x, double y) {
    if (cp(l1, x, y) && cp(l2, x, y) && cp(l3, x, y)) return true;
    return false;
}
int get_left(double  high) {
    if (m == 0) return 1;
    double a = high * n / m;
    return (int)(a + 1);
}
int get_right(double high) {
    if (n == p) return n - 1;
    double result = (high - b) / k;
//    cout << result << endl;
    //cout << result << endl;
    //if (result == (int)result) {
    //    //if (k * (int)result + b == high)
    //        //return (int)(result-1);
    //    double x1 = n - (int)result, y1 = m - (int)high;
    //    if (m * x1 == y1 * (n - p)) return (int)(result - 1);
    //}
    //return (int)(result);
    int k_sign;
    if (n > p) k_sign = 1;
    else k_sign = -1;
    if (k_sign > 0) {
        result = max((int)p + 1, (int)(result));
        for (; high * (n - p) > m * (result - p); result++) ; 
        return result - 1;
    }
    if (k_sign < 0) {
        result = min((int)p - 1, (int)(result) + 1);
        int tmp;
        for (; ; result--) {
            tmp = high * (p - n) - m * (p - result);
            if (tmp <= 0) break;
        }
        if (tmp < 0) return result;
        else return result - 1;
    }
}
int main()
{
    in >> n >> m >> p;
    int maxx = max(n, p); 
    int maxy = m;
    int sum = 0;
    p1.x = 0; p1.x = 0; p2.x = n; p2.y = m; p3.x = p; p3.y = 0;
    l1.a = p1; l1.b = p2; l2.a = p2; l2.b = p3; l3.a = p3; l3.b = p1;
    mid.x = (n + p) / 3;
    mid.y = m / 3;
    int x, y;
    double high;
    k = m / (n - p);
    b = m - k * n;
    for (high = 1; high < m; high++) {
        int left = get_left(high);
        int right = get_right(high);
        //cout << left << ":" << right << endl;
        if (left <= right) sum += (right - left + 1);
    }
    //for (x = 0; x <= maxx; x++) {
    //    for (y = 0; y <= maxy; y++) {
    //        if (check(x, y)) sum++;
    //    }
    //}
    out << sum << endl;
}

