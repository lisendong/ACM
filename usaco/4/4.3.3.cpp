/*
ID: lisendo1
PROG: race3 
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
ifstream in("race3.in"); 
ofstream out("race3.out");
int arr[60][60] = {0};
int global_flag = 0;
int n;
void bfs1(int num, bool flag[60]) {
    queue<int> q; 
    q.push(num);
    while (!q.empty()) {
        int cur = q.front();
        flag[cur] = true;
        q.pop();
        for (int i = 0; i <= n; i++) { // from zero!!!!
            if (arr[cur][i] == 1 && i != global_flag && !flag[i]) { // attention!!! cur != global_flag, not i != global_flag
                q.push(i);
            }
        }
    }
}

void bfs2(int num, bool flag[60]) {
    queue<int> q;
    q.push(num);
    while (!q.empty()) {
        int cur = q.front();
        flag[cur] = true;
        q.pop();
        for (int i = 0; i <= n; i++) { // from zero!!!!
            if (arr[cur][i] == 1 && !flag[i]) {
                q.push(i);
            }
        }
    }
    //flag[num] = false;
}

int main()
{
    //int n = 1;
    n = 0;// from zero!!!!
    int a;
    while (in >> a) {
        if (a == -1 || a == -2) break; // if a == -2 break!!!
        arr[n][a] = 1;
        while (in >> a) {
            if (a == -2) break;
            arr[n][a] = 1;
        }
        n++;
    }
    cout << n << endl;
    int i, j;
    int resulta[60] = {0}, numa = 0;
    int resultb[60] = {0}, numb = 0;
    for (i = 1; i < n; i++) {
        bool flag1[60] = {0};
        global_flag = i;// delete all arr of i
        bfs1(0, flag1); // from zero!!!!!
        if (!flag1[n]) {
            resulta[numa++] = i;
        }
            //bool flag1[60] = {0};
            //bfs1(1, flag1); // delte all arr of global_flag
            bool flag2[60] = {0};
            bfs2(i, flag2); // do not delte any arr
            for (j = 0; j <= n; j++) { // j from zero!!!
                if (flag1[j] && flag2[j]) break;
            }
            if (j > n) resultb[numb++] = i;
        //}
    }
    out << numa;
    for (i = 0; i < numa; i++) out << " " << resulta[i];
    out << endl;
    out << numb;
    for (i = 0; i < numb; i++) out << " " << resultb[i];
    out << endl;
    return 0;
}
