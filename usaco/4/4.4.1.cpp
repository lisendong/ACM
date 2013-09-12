/*
ID: lisendo1
PROG: shuttle
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
#include<map>
#include<vector>
#define MAXN 200
#define nil -1
#define oo 100000000
using namespace std;
ifstream in("shuttle.in"); 
ofstream out("shuttle.out");
int n;
int data[100];// please ensure the arr space is enough!!!!
int result[10000];
int sum(int a[20], int start, int end) {
    int result = 0;
    for (int i = start; i <= end; i++) result+=a[i];
    return result;
}
bool dfs(int p, int step) {
    int i;
    if (p == n+1 && sum(data, 1, n) == 2 * n && sum(data, n+2, 2*n+1) == n) {
        cout << "get it!" << endl;
        for (i = 0; i < step; i++) {
            if (i != 0 && i % 20 == 0)out << endl;
            if (i % 20 != 0) out << " ";
            out << result[i];
        }
        out << endl;
        return true;
    }
    if (p >= 3 && data[p-2] == 1 && data[p-1] == 2) {
        result[step] = p-2;
        data[p] = data[p-2];
        data[p-2] = 0;
        if (dfs(p-2, step+1)) {
            return true;
        }
        data[p-2] = data[p];
        data[p] = 0;
    }
    if (p >= 2 && data[p-1] == 1) {
        result[step] = p-1;
        data[p] = data[p-1];
        data[p-1] = 0;
        if (dfs(p-1, step+1)) {
            return true;
        }
        data[p-1] = data[p];
        data[p] = 0;
    }
    if (p < 2*n+1 && data[p+1] == 2) {
        result[step] = p+1;
        data[p] = data[p+1];
        data[p+1] = 0;
        if (dfs(p+1, step+1)) {
            return true;
        }
        data[p+1] = data[p];
        data[p] = 0;
    }
    if (p < 2*n && data[p+2] == 2 && data[p+1] == 1) {
        result[step] = p+2;
        data[p] = data[p+2];
        data[p+2] = 0;
        if (dfs(p+2, step+1)) {
            return true;
        }
        data[p+2] = data[p];
        data[p] = 0;
    }
    return false;
}
int main()
{
    in >> n;
    int i;
    for (i = 1; i <= n; i++) data[i] = 1;
    data[i] = 0;
    for (i++; i <= 2 * n + 1; i++) data[i] = 2;
    dfs(n+1, 0);
}
