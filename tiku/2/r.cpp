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
unsigned long long result = 0;
unsigned long long cal(int n, int ipow) {
    int i;
    unsigned long long sum = 0;
    for (i = 1; i <= n; i++) {
        sum += pow(i, ipow);
    }
    return sum;
}
int main()
{
    int n;
    while (cin >> n) {
        for (int ipow = 2; ipow <= 4; ipow++) {
            unsigned long long one = cal(n, ipow);
            unsigned long long two = pow((1 + n) * n / 2, ipow);
            cout << one << " " << two - one;
            if (ipow != 4) cout << " ";
        }
        cout << endl;
    }
}



