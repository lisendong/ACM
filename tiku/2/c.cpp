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
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        vector <long long > r1, r2;
        vector <long long > op1, op2;
        long long a;
        scanf("%lld",  &a);
        char o;
        r1.push_back(a);
        o = getchar();
        while (o != 10) {
            op1.push_back(o);
            scanf("%lld", &a);
            r1.push_back(a);
            o = getchar();
        }
        op2 = op1;
        r2 = r1;
        int i = 0;
        while (i < op1.size()) {
            if (op1[i] == '+') {
                long long rl = r1[i] + r1[i+1];
                r1.erase(r1.begin() + i);
                r1.erase(r1.begin() + i);
                r1.insert(r1.begin() + i, rl);
                op1.erase(op1.begin() + i);
            }
            else 
                i++;
        }
        long long max = 1;
        for (i = 0; i < r1.size(); i++) max *= r1[i];
        i = 0;
        while (i < op2.size()) {
            if (op2[i] == '*') {
                long long rl = r2[i] * r2[i+1];
                r2.erase(r2.begin() + i);
                r2.erase(r2.begin() + i);
                r2.insert(r2.begin() + i, rl);
                op2.erase(op2.begin() + i);
            }
            else 
                i++;
        }
        long long min = 0;
        for (i = 0; i < r2.size(); i++) min += r2[i];
        cout << "The maximum and minimum are " << max << " and " << min << "." << endl;
    }
}



