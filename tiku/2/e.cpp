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
#include<deque>
#include<list>
#include<vector>
#define oo 0x7FFFFFF
#define MAXN 25
using namespace std;
string s[110];
int dis[110][110];
string result[110];
int result_num;
//void prim() {
//    int visit[110] = {0};
//    int dist[110] = {0};
//    int i, cur;
//    for (i = 1; i <= N; i++) {
//        dist[i] = oo;
//    }
//    dist[1] = 0;
//    while (true) {
//        int min = oo, min_dis = oo;
//        for (i = 1; i <= N; i++) {
//             if (dist[i] < min) {
//                 min = i;
//                 min_dis = dist[i];
//             }
//        }
//        if (min == oo) break;
//        for (i = 1; i <= N; i++)
//    }
//}
int caldis(string a, string b) {
    int i;
    int sum = 0;
    for(i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] != b[i]) break;
        sum++;
    }
    return sum;
}
int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        int i, j;
        cin >> N;
        for (i = 1; i <= N; i++) {
            cin >> s[i];
        }
        for (i = 1; i  <= N; i++) {
            for (j = i; j <= N; j++) {
                if (j == i) dis[i][j] = 0;
                else {
                    dis[i][j] = caldis(s[i], s[j]);
                    dis[j][i] = dis[i][j];
                }
            }
        }
        bool visit[110] = {0};
        int cur = 1;
        result_num = 1;
        result[result_num] = s[cur];
        visit[1] = true;
        int sum = 0;
        sum += s[cur].size();
        //for (i = 1; i <= N; i++) dis[i][cur] = -1;
        while (result_num < N) {
            int max = -1, max_dis = -1;
            for (i = 1; i <= N; i++) {
                if (visit[i] == false && dis[cur][i] > max_dis) {
                    max_dis = dis[cur][i];
                    max = i;
                }
            }
            //if (max == -1) break;
            //cout << max << endl;
            //cout << s[max] << endl;
            result[++result_num] = s[max];
            visit[max] = true;
            sum += s[max].size() - dis[cur][max];
            cur = max;
        }
        cout << sum << endl;
        for (i = 1; i <= N; i++) {
            cout << result[i] << endl;
        }
    }
}



