/*
ID: lisendo1
PROG: agrinet 
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#define oo 100000
#define MAXN 120
using namespace std;
ifstream in("agrinet.in"); 
ofstream out("agrinet.out");
int a[MAXN][MAXN] = {0};
int main()
{
    int N;
    in >> N;
    int i, j, sum = 0;
    int dis[MAXN], visit[MAXN];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
           in >> a[i][j];
        }
    }
    memset(dis, oo, sizeof(dis));
    memset(visit, false, sizeof(visit));
    //init
    visit[0] = true;
    for (i = 1; i < N ; i++) {
        if (a[0][i] > 0) {
            dis[i] = a[0][i];
        }
    }
    for (i = 1; i < N; i++) {
       //findmin
       int min = oo, minj;
       for (j = 0; j < N; j++) {
           if (visit[j] == false && dis[j] < min) {
               min = dis[j];
               minj = j;
           }
       }
       visit[minj] = true;
       sum += dis[minj];
       for (j = 0; j < N; j++) {
           if (a[j][minj] > 0 && a[j][minj] < dis[j]) {
               dis[j] = a[j][minj];
           }
       }
    }
    out << sum << endl;
     
}

