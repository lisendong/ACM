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
double per;
int numcall;
int numplan;
struct _plan {
    int num;
    int month;
    int price;
    float per_call;
};
_plan plan[110];
int lcm(int a, int b) {
    int max = (a >= b?a:b),min = (a < b?a:b),i;
    for(i = 1;;++i)
    {
        if((max * i) % min == 0)
        {
            return (max * i);
        }
    }
}
int cmp(_plan a, _plan b) {
    int month = lcm(a.month, b.month); 
    double feea = (month / a.month) * a.price + month * numcall * a.per_call;
    double feeb = (month / b.month) * b.price + month * numcall * b.per_call;
    return (feea < feeb);
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> per >> numcall >> numplan;
        int i;
        plan[0].num = 0;
        plan[0].price = 0;
        plan[0].month = 1;
        plan[0].per_call = per;
        for (i = 1; i <= numplan; i++) {
            cin >> plan[i].month >> plan[i].per_call >> plan[i].price;
            plan[i].num = i;
        }
        sort(plan + 0, plan + numplan + 1, cmp);
        cout << plan[0].num << endl;
    }
}



