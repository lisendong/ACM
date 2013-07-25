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
#define pi 3.141592654
using namespace std;
int hong[110][110];
int need_to_check[440][2];
int need_to_check_num = 0;
int T, L, H, N;
const double one = 0.25 * pi;
//const double two = 1 -  2 * ((1 - 0.5 * sqrt(3) + 1) * 0.25 - 1 / 12 * pi);
//const double two = 1 * 0.25 * sqrt(3) + 2 * 1 / 12 * pi;
const double two = 0.9566114774905181;
bool check(int x, int y) {
    int i;
    for (i = 1; i <= N; i++) {
        if (hong[i][0] == x && hong[i][1] == y) return true;
    }
    return false;
}
bool exists(int x, int y) {
    int i;
    for (i = 0; i < need_to_check_num; i++) {
        if (need_to_check[i][0] == x && need_to_check[i][1] == y) return true;
    }
    return false;
}
void push_check(int x, int y) {
    if (!exists(x, y)) {
        need_to_check[need_to_check_num][0] = x;
        need_to_check[need_to_check_num][1] = y;
        need_to_check_num ++;
    }
}
void push_need(int x, int y) {
    push_check(x, y);
    push_check(x + 1, y);
    push_check(x , y + 1);
    push_check(x + 1, y + 1);
}
int main()
{
    //printf("%.2lf %.2lf", one, two);
    cin >> T;
    while (T--) {
        cin >> L >> H; 
        cin >> N; 
        int i, j;
        need_to_check_num = 0;
        for (i = 1; i <= N; i++) {
            cin >> hong[i][0] >> hong[i][1];
            push_need(hong[i][0], hong[i][1]);
        }
        double sum = 0;
        //cout << need_to_check_num << endl;
        for (int k = 0; k < need_to_check_num; k++) {
                i = need_to_check[k][0];
                j = need_to_check[k][1];
                //cout << i << "," << j << endl;
                bool wn = check(i - 1, j);
                bool ws = check(i - 1, j - 1);
                bool en = check(i, j);
                bool es = check(i, j - 1);
                if (wn && es || ws && en) {
                    sum += 1;
                }
                else if(wn && ws || en && es || wn && en || ws && es) {
                    sum += two;
                }
                else if (wn || ws || en || es) {
                    sum += one;
                }
        }
        printf("%.2lf\n", L * H - sum);
    }
}


