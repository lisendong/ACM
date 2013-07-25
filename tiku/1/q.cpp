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
struct object {
    int price;
    int weight;
};
struct object o[1010];
int MW[110];
int dp[1010][40];
int main()
{
    int T, N, G;
    cin >> T;
    while (T--) {
        cin >> N;
        int i, j;
        for (i = 1; i <= N; i++) {
            cin >> o[i].price;
            cin >> o[i].weight;
        }
        cin >> G;
        int maxmw = 0;
        for (i = 1; i <= G; i++) {
            cin >> MW[i];
            if (MW[i] > maxmw) maxmw = MW[i];
        }
        //01背包问题
        for (i = 1; i <= N; i++) {//货物
            for (j = 1; j <=maxmw; j++) {//背包容量
                if (i == 1) {
                    dp[i][j] = (o[i].weight <= j ? o[i].price : 0);
                }
                if (o[i].weight <= j)
                    dp[i][j] = max(dp[i - 1][j], o[i].price + dp[i - 1][j - o[i].weight]);
                else 
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int sum = 0;
        for (i = 1; i <= G; i++) {
            sum += dp[N][MW[i]];
        }
        cout << sum << endl;
    }
}


