/*
ID: lisendo1
PROG: buylow
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
#define oo 100000000.0
using namespace std;
ifstream in("buylow.in"); 
ofstream out("buylow.out");
void iadd(int a[MAXN], int b[MAXN]) {
    int jinwei = 0;
    int c[MAXN] = {0};
    for (int i = 0; i < MAXN; i++) {
        c[i] = (a[i] + b[i] + jinwei) % 10;
        jinwei = (a[i] + b[i] + jinwei) / 10;
    }
    for (int i = 0; i < MAXN; i ++) {
        a[i] = c[i];
    }
}
int main()
{
    int n;
    in >> n;
    int i, j;
    int a[6000], max_length[6000] = {0}, max_num[6000][MAXN] = {0};
    for (i = 0; i < n; i++) {
        in >> a[i];
        max_length[i] = 1;
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (a[j] > a[i] && max_length[j] + 1 > max_length[i]) {
                max_length[i] = max_length[j] + 1;
            }
        }
    } 
    max_num[0][0] = 1;
    for (i = 1; i < n; i++){
        if (max_length[i] == 1) max_num[i][0] = 1;
        else {
            map<int, bool> m;
            for (j = i - 1; j >= 0; j--) {
                if (max_length[i] == max_length[j] + 1 && a[j] > a[i] && m.find(a[j]) == m.end()) {
                    m[a[j]] = true;
                    iadd(max_num[i], max_num[j]);
                    //max_num[i] += max_num[j];
                }
            }
        }
    }
    int resulta = 0, resultb[MAXN] = {0};
    for (i = 0; i < n; i++) {
        if (max_length[i] > resulta) resulta = max_length[i];
    }
    map<int, bool> m;
    for (i = n - 1; i >= 0; i--) {
        if (max_length[i] == resulta && m.find(a[i]) == m.end())  {
            //resultb += max_num[i];
            iadd(resultb, max_num[i]);
            m[a[i]] = true;
        }
    }
    out << resulta << " ";
    for (i = MAXN - 1; i >= 0; i--) {
        if (resultb[i] > 0) break;
    }
    for (; i >= 0; i--) {
        out << resultb[i];
    }
    out << endl;
    return 0;
}
