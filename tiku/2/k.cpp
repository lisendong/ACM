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
int flag[210][210][210];
int ans = oo;
void dfs(int total, int a, int b, int c, int ca, int cb, int cc, int d) {
    if (a == d || b == d || c == d) {
        if (total < ans) {
            ans = total;
        }
        return ;
    }
    int poor;
    if (a  > 0 && b < cb) {
        poor = min(a, cb - b);
        if (flag[a-poor][b+poor][c] > total+poor)
        {flag[a-poor][b+poor][c] = total+poor;
        dfs(total + poor, a - poor, b + poor, c, ca, cb, cc, d);}
    }
    if (a > 0 && c < cc) {
        poor = min(a, cc - c);
        if (flag[a-poor][b][c+poor] > total+poor)
        {flag[a-poor][b][c+poor] = total+poor;
        dfs(total + poor, a - poor, b, c + poor, ca, cb, cc, d);}
    }
    if (b > 0 && a < ca) {
        poor = min(b, ca - a);
        if (flag[a+poor][b-poor][c] > total+poor)
        {flag[a+poor][b-poor][c] = total+poor;
        dfs(total + poor, a + poor, b -  poor, c, ca, cb, cc, d);}
    }
    if (b > 0 && c < cc) {
        poor = min(b, cc - c);
        if (flag[a][b-poor][c+poor] > total+poor)
        {flag[a][b-poor][c+poor] = total+poor;
        dfs(total + poor, a, b -  poor, c + poor, ca, cb, cc, d);}
    }
    if (c > 0 && a < ca) {
        poor = min(c, ca - a);
        if (flag[a+poor][b][c-poor] > total+poor)
        {flag[a+poor][b][c-poor] = total+poor;
        dfs(total + poor, a + poor, b, c - poor, ca, cb, cc, d);}
    }
    if (c > 0 && b < cb) {
        poor = min(c, cb - b);
        if (flag[a][b+poor][c-poor] > total+poor)
        {flag[a][b+poor][c-poor] = total+poor;
        dfs(total + poor, a, b + poor , c - poor, ca, cb, cc, d);}
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        while(true) {
            ans = oo;
            for (int i = 0; i < 210; i++) {
                for (int j = 0; j < 210; j++) {
                    for (int k = 0; k < 210; k++) {
                        flag[i][j][k] = oo;
                    }
                }
            }
            dfs(0, 0, 0, c, a, b, c, d);
            if (ans != oo) {
                cout << ans << " " << d << endl;
                break;
            }
            d--;
        }
    }
}



