/*
ID: lisendo1
PROG: range
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
using namespace std;
ifstream in("range.in"); 
ofstream out("range.out");
int N;
bool data[251][251];
bool flag[251][251] = {0};
bool judge(int i, int j, int len) {
    int r, c;
    if (i + len - 1 >= N || j + len - 1 >= N) {
        flag[i][j] = 0;
        return 0;
    }
    if (len == 1) {
        flag[i][j] = data[i][j];
        return data[i][j];
    }
    if (flag[i][j] == 0) {
        flag[i][j] = 0;
        return 0;
    }
    //for (r = i; r <= i + len - 1; r++) {
    //    for (c = j; c <= j + len - 1; c++) {
    //        if (data[r][c] == 0) {
    //            flag[i][j][len] = 0;
    //            return 0;
    //        }
    //    }
    //}
    for (r = i; r <= i + len - 1; r++) {
        if (data[r][j + len - 1] == 0) {
            flag[i][j] = 0;
            return 0;
        }
    }
    for (c = j; c <= j + len - 1; c++) {
        if (data[i + len - 1][c] == 0) {
            flag[i][j] = 0;
            return 0;
        }
    }
    flag[i][j] = 1;
    return 1;
}
int main()
{
    in >> N;
    int i, j;
    char ch;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            in >> ch;
            if (ch == 10) in >> ch;
            data[i][j] = (ch == '1');
        }
    }
    int weidu;
    for (weidu = 1; weidu <= N; weidu++) {
        int sum = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (judge(i, j, weidu)) sum++;
            }
        }
        if (weidu != 1 && sum != 0)
        out << weidu << " " << sum << endl;
    }
    return 0;
}

