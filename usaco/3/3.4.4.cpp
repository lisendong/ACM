/*
ID: lisendo1
PROG: rockers
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
#define MAXN 25
using namespace std;
ifstream in("rockers.in"); 
ofstream out("rockers.out");
int N, T, M;
int s[MAXN];
int main()
{
    in >> N >> T >> M;
    int limit = (1 << N) - 1; 
    int i;
    for (i = 0; i < N; i++) in >> s[i];
    int min = 0;
    int min_flag = 0;
    for (i = 1; i <= limit; i++) {
        int rest_dist = M - 1;
        int rest_song = i;
        int song_num = 0;
        int cur_dist_cap = T;
        int j;
        for (int j = 0; j < N; j++) {
            int if_put = (int)(rest_song & 1);
            rest_song >>= 1;
            if (if_put == 1) {
                if (cur_dist_cap >= s[j]) {
                    cur_dist_cap -= s[j];
                    song_num++;
                }
                else {
                    if (rest_dist == 0) break;
                    if (s[j] > T) break;
                    else {
                        rest_dist --;
                        cur_dist_cap = T;
                        cur_dist_cap -= s[j]; 
                        song_num++;
                    }
                }
            }
            if (rest_song == 0) break;
        }
        if (song_num > min) {min = song_num; min_flag = i;}
    }
    out << min << endl;
    cout << min_flag << endl;
}

