//lsd 
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
    int m, n, t;
    while (cin >> m >> n >> t) {
        if (m < n) {
            int tmp;
            tmp = n;
            n = m;
            m = tmp;
        }
        int max_burger = 0, min_beer = t;
        int num_n;
        for (num_n = 0; num_n * n <= t; num_n++) {
            int rest_time = t - num_n * n;
            int total_burger = num_n + (rest_time / m);
            int beer = rest_time % m;
            if (min_beer == 0 && beer == 0 && total_burger > max_burger) {
                max_burger = total_burger;
            }
            if (min_beer != 0 && beer != 0 && beer < min_beer) {
                min_beer = beer;
                max_burger = total_burger;
            }
            if (min_beer != 0 && beer != 0 && beer == min_beer && total_burger > max_burger) {
                min_beer = beer;
                max_burger = total_burger;
            }
            if (min_beer != 0 && beer == 0) {
                min_beer = beer;
                max_burger = total_burger;
            }
        }
        cout << max_burger;
        if (min_beer != 0) {
            cout << " " << min_beer;
        }
        cout << endl;
    }
}


