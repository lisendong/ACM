/*
ID: lisendo1
PROG: shopping
LANG: C++
*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
using namespace std;
ifstream in("shopping.in"); 
ofstream out("shopping.out");
struct offer {
    int n;
    int d[10][2];
    int p;
};
//struct offer o[120];
vector <struct offer > o;
int s, b;
int pnum[10] = {0};
int pvolum[10] = {0};
int price[10] = {0};
int target;
const int MAXP = 60000;
int dp[MAXP];
int use(int num, int offer) {
    int a[10];
    int i, j;
    for (i = b - 1; i >= 0; i--) {
        a[i] = num % 10;
        num /= 10;
    }
    for (i = 0; i < b; i++) {
        for (j = 0; j < o[offer].n; j++) {
            if (pnum[i] == o[offer].d[j][0]) {
                if (a[i] < o[offer].d[j][1]) return -1;
                a[i] -= o[offer].d[j][1];
            }
        }
    }
    int result = 0;
    for (i = 0; i < b; i++) {
        result = result * 10 + a[i];
    }
    return result;
}
int main()
{
    in >> s;
    int i, j;
    for (i = 0; i < s; i++) {
        struct offer *tmpo = (struct offer *)malloc(sizeof(struct offer));
        in >> tmpo->n;
        for (j = 0; j < tmpo->n; j++) {
            in >> tmpo->d[j][0] >> tmpo->d[j][1]; // 0 stand for product code, 1 stand for item num
        }
        in >> tmpo->p;
        o.push_back(*tmpo);
    }
    in >> b;
    for (i = 0; i < b; i++) {
        in >> pnum[i] >> pvolum[i] >> price[i];
    }
    target = 0; 
    for (i = 0; i < b; i++) {
        target = target * 10 + pvolum[i];
    }
    for (i = 0; i < s; i++) {
        int flag = 0;
        for (j = 0; j < o[i].n; j++) {
            flag = 0;
            for (int k = 0; k < b; k++) {
                if (o[i].d[j][0] == pnum[k]) {
                    flag = 1;
                }
            }
            if (flag == 0) break;
        }
        if (!flag) {
            o.erase(o.begin() + i);
            //out << o.size() << endl;
            i--;
        }
    }
    s = o.size();
    for (i = 0; i < s; i++) {
        int total_sum = 0;
        for (j = 0; j < o[i].n; j++) {
            int product_num = o[i].d[j][0];
            for (int k = 0; k < b; k++) {
                if (product_num == pnum[k]) {
                    total_sum += price[k] * o[i].d[j][1];
                }
            }
        }
        o[i].p = total_sum - o[i].p;
    }
    for (j = 0; j < s; j++) {
        for (i = 0; i <= target; i++) {
            if (use(i, j) >= 0) {
                int resti = use(i, j);
                int reduced = o[j].p;
                dp[i] = max(dp[i], dp[resti] + reduced);
            }
        }
    }
    int origin_price = 0;
    for (i = 0; i < b; i++) {
        origin_price += pvolum[i] * price[i];
    }
    out << origin_price - dp[target] << endl;
}

